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
    if config == 'classic':
        layout = 'classic'
    libcalamares.utils.target_env_call(['llx-desktop-layout','set',layout])
    return None

def run():
    """
        
    """
    config = libcalamares.globalstorage.value('lliurexDesktopLayout')
    return system_addons(config)
