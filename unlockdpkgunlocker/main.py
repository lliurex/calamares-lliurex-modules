#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#   Copyright 2018, Raul Rodrigo Segura <raurodse@gmail.com>
#
#   GPLv3

import libcalamares
from pathlib import Path

def run():
    a = libcalamares.globalstorage.value("rootMountPoint")
    x = Path("{}/run/disableMetaProtection.token".format(a))
    x.touch()
    return None


