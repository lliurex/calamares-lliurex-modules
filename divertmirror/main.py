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
import psutil

from libcalamares.utils import check_target_env_call, target_env_call

def run():

    root = Path( libcalamares.globalstorage.value("rootMountPoint") )
    sources_list = root.joinpath('etc','apt','sources.list')
    all_content=[]
    with sources_list.open("r",encoding="utf-8") as fd:
        for line in fd.readlines():
            try:
                line.index("http://mirror")
                all_content.append("#{}".format(line))
            except Exception as e:
                all_content.append(line)
    
    with sources_list.open("w",encoding="utf-8") as fd:
        fd.writelines(all_content)

    cdrom_path = root.joinpath("cdrom")
    dev_cdrom = Path("/dev/cdrom")
    cdrom_path.mkdir(parents=True,exist_ok=True)
    if dev_cdrom.exists():
        subprocess.Popen(("mount -o loop {} {}").format("/dev/cdrom",cdrom_path),shell=True).communicate()
    else:
        subprocess.Popen(("mount --bind /cdrom {}").format(cdrom_path),shell=True).communicate()
    return None


