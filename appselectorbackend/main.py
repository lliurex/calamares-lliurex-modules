#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#   Copyright 2018, Raul Rodrigo Segura <raurodse@gmail.com>
#
#   GPLv3

import libcalamares
import subprocess
import abc
from pathlib import Path

from libcalamares.utils import check_target_env_call, target_env_call

class PackageManager(metaclass=abc.ABCMeta):
    """
    Package manager base class. A subclass implements package management
    for a specific backend, and must have a class property `backend`
    with the string identifier for that backend.
    Subclasses are collected below to populate the list of possible
    backends.
    """
    backend = None

    @abc.abstractmethod
    def install(self, pkgs, from_local=False):
        """
        Install a list of packages (named) into the system.
        Although this handles lists, in practice it is called
        with one package at a time.
        @param pkgs: list[str]
            list of package names
        @param from_local: bool
            if True, then these are local packages (on disk) and the
            pkgs names are paths.
        """
        pass

    @abc.abstractmethod
    def remove(self, pkgs):
        """
        Removes packages.
        @param pkgs: list[str]
            list of package names
        """
        pass

    @abc.abstractmethod
    def update_db(self):
        pass

    def run(self, script):
        if script != "":
            check_target_env_call(script.split(" "))

    def install_package(self, packagedata, from_local=False):
        """
        Install a package from a single entry in the install list.
        This can be either a single package name, or an object
        with pre- and post-scripts. If @p packagedata is a dict,
        it is assumed to follow the documented structure.
        @param packagedata: str|dict
        @param from_local: bool
            see install.from_local
        """
        if isinstance(packagedata, str):
            self.install([packagedata], from_local=from_local)
        else:
            self.run(packagedata["pre-script"])
            self.install([packagedata["package"]], from_local=from_local)
            self.run(packagedata["post-script"])

    def remove_package(self, packagedata):
        """
        Remove a package from a single entry in the remove list.
        This can be either a single package name, or an object
        with pre- and post-scripts. If @p packagedata is a dict,
        it is assumed to follow the documented structure.
        @param packagedata: str|dict
        """
        if isinstance(packagedata, str):
            self.remove([packagedata])
        else:
            self.run(packagedata["pre-script"])
            self.remove([packagedata["package"]])
            self.run(packagedata["post-script"])


class PMApt(PackageManager):
    backend = "apt"

    def install(self, pkgs, from_local=False):
        check_target_env_call(["apt-get", "-q", "-y", "install"] + pkgs)

    def remove(self, pkgs):
        check_target_env_call(["apt-get", "--purge", "-q", "-y",
                               "remove"] + pkgs)
        check_target_env_call(["apt-get", "--purge", "-q", "-y",
                               "autoremove"])

    def update_db(self):
        check_target_env_call(["apt-get", "update"])

    def update_system(self):
        # Doesn't need to update the system explicitly
        pass



#  ------------------------------------------------------------------------------------------------------------------

def get_list_packages():

    return libcalamares.globalstorage.value("lliurexExtraApps")

def get_system_config():
    
    return libcalamares.globalstorage.value("lliurexExtraServices")

def system_addons( rmp, config, pkgman ):
    '''
        Create link to resolv.conf
    '''
    
    analytics_path = Path("{rootmountpoint}/etc/lliurex-analytics/status".format(rootmountpoint=rmp))
    analytics_path.parent.mkdir(exist_ok=True, parents= True)
    with analytics_path.open("w",encoding='utf-8') as fd:
        if 'statistics' in config:
            # Enable Statistics
            fd.write('yes\n')
        else:
            fd.write('no\n')

    if 'inventory' in config:
        pkgman.install(['fusioninstall'])

    return None

def run():
    if libcalamares.globalstorage.value("hasInternet"):
        pkgman = PMApt()
        packages = get_list_packages()
        pkgman.update_db()
        for package in packages :
            try:
                pkgman.install([package])
            except subprocess.CalledProcessError:
                libcalamares.utils.warning("Cound not install package {package}".format(package=package))
    else:
        libcalamares.utils.warning("Package installation has been skipped: no internet")

    system_addons( libcalamares.globalstorage.value("rootMountPoint"), get_system_config(), pkgman) 
    return None


