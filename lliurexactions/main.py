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

    return None


