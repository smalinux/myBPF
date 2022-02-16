#!/usr/bin/python3
# Copyright (c) PLUMgrid, Inc.
# Licensed under the Apache License, Version 2.0 (the "License")

# run in project examples directory with:
# sudo ./hello_world.py"
# see trace_fields.py for a longer example

from bcc import BPF

# This may not work for 4.17 on x64, you need replace kprobe__sys_clone with kprobe____x64_sys_clone
print("Tracing sys_mkdir()... Ctrl-C to end.")
BPF(text='int kprobe__sys_mkdir(void *ctx) { bpf_trace_printk("Hello, World!\\n"); return 0; }').trace_print()
