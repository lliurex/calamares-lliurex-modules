#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#
#   Copyright 2021, Raul Rodrigo Segura <raurodse@gmail.com>
#

import libcalamares
import os

def system_addons(config):
    '''
        Set default desktop layout
    '''
    layout = 'default'
    if config['layout'] == 'classic':
        layout = 'classic'
    libcalamares.utils.target_env_call(['llx-desktop-layout','set',layout])
    return None

def run():
    """
        
    """
    config = libcalamares.globalstorage.value('lliurexDesktopLayout')
    return system_addons(config)

def system_addons( rmp, config, pkgman ):
    '''
        Create link to resolv.conf
    '''
    
    analytics_path = Path("{rootmountpoint}/etc/lliurex-analytics/status".format(rootmountpoint=rmp)
    analytics_path.parent.mkdir(exist_ok=True, parents= True)
    with analytics_path.open("w",encoding='utf-8') as fd:
        if config['statistics']:
            # Enable Statistics
            fd.write('yes\n')
        else:
            fd.write('no\n')

    if config['inventory']:
        pkgman.install('fusioninstall')

    return None




def run():
    if libcalamares.globalstorage.value("hasInternet"):
        pkgman = PMApt()
        packages = get_list_packages()
        pkgman.update_db()
        for package in packages :
            try:
                pkgman.install(package)
            except subprocess.CalledProcessError:
                libcalamares.utils.warning("Cound not install package {package}".format(package=package))
    else:
        libcalamares.utils.warning("Package installation has been skipped: no internet")

    system_addons( libcalamares.globalstorage.value("rootMountPoint"), get_system_config(), pkgman) 
    return None


