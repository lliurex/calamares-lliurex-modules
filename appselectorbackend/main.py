#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#   Copyright 2018, Raul Rodrigo Segura <raurodse@gmail.com>
#
#   GPLv3

    def install_package(self, list_packages, package):
        found = False
        for list_index in range(0,len(list_packages)):
            install_keys = [ x for x in ['install','try_install'] if x in list_packages[list_index] ]
            for x in install_keys:
                if package in list_packages[list_index][x]:
                    found = True
        if not found:
            if 'try_install' not in list_packages[0]:
                list_packages[0] = {'try_install':()}
            list_packages[0]['try_install'] = list_packages[0]['try_install'] + (package,)
        return list_packages

    def system_addons(rmp,config):
    '''
        Create link to resolv.conf
    '''
    if config['flash']:
        # install Flash by epic
        libcalamares.utils.target_env_call(['epic','-u','install','/usr/share/zero-lliurex-flash/flash.epi'])

    analytics_path = "{rootmountpoint}/etc/lliurex-analytics/".format(rootmountpoint=rmp)
    os.system("mkdir -p {ap}".format(ap=analytics_path))
    if config['statistics']:
        # Enable Statistics
        with open(os.path.join(analytics_path,"status"),"w") as fd:
            fd.write('yes\n')
    else:
        with open(os.path.join(analytics_path,"status"),"w") as fd:
            fd.write('no\n')


    return None

def run():
    """
    Create ubiquity modifications
    :return:
    """
    root_mount_point = libcalamares.globalstorage.value("rootMountPoint")
    config = libcalamares.globalstorage.value('systemaddons')
    return system_addons(root_mount_point,config)
