Set up
======

On all nodes (CentOS 7):
```sh
# yum install openmpi
# rpm -Uvh support/libfabric-1.4.2-5.fc27.x86_64.rpm
```

On master node:
```sh
# systemctl stop iptables
```

Configure ssh shared key communication from master to all nodes.
Configure NFS for all nodes.

Then (not exactly sure):
```sh
# mpirun -np 4 --host localhost,myhost2,myhost3 /my/nfs/dir/mpitest/_build/test2 
```
