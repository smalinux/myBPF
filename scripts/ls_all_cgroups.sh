#!/bin/bash

for a in $(cat /sys/fs/cgroup/cgroup.procs);
	do echo "$a => `ps -p $a -o comm=`";
done
