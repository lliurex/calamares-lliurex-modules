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

def run():
    root = Path(libcalamares.globalstorage.value("rootMountPoint"))
    
    live_list_path = root.joinpath('etc','apt','sources.list.d','live.list')
    opensshserver_path = root.joinpath('lib','systemd','system','ssh.service')

    if live_list_path.exists():
        live_list_path.unlink()

    if opensshserver_path.exists():
        target_env_call(['dpkg-reconfigure','openssh-server'])

    locale = root.joinpath("etc","default","locale")
    with locale.open("r") as fd:
        content = fd.readlines()
    for x in range(0,len(content)): 
        if content[x].startswith("LANG"):
            continue
        if content[x].find("@valencia") >= 0 :
            z = content[x].split("=")
            content[x] = z[0] + "=ca_ES.UTF-8\n"
    with locale.open("w") as fd:
        fd.writelines(content)




    return None


