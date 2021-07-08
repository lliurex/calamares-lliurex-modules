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

    root = Path( libcalamares.globalstorage.value("rootMountPoint") )
    sources_list = root.joinpath('etc','sources.list')
    all_content=[]
    with sources_list.open("r",encoding="utf-8") as fd:
        for line in fd.readlines():
            try:
                line.index("http://mirror")
                if line.strip().startswith("#"):
                    all_content.append(line.strip()[1:])
            except Exception as e:
                all_content.append(line)
    
    with sources_list.open("w",encoding="utf-8") as fd:
        fd.writelines(all_content)

    return None


