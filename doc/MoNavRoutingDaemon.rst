Introduction
++++++++++++

The Routing Daemon acts as a background service that can be queried from other programs or the console.

Details
+++++++

The daemon uses QService to act as a daemon in a Linux environment and a service in a Windows enviroment.

Its command line arguments are:

usage: MoNavD -i | -install installs the service usage: MoNavD -u | -uninstall uninstalls the service usage: MoNavD -t | -terminate terminates the service usage: MoNavD -v | -version displays version and status

The Routing Daemon can be tested with the accompanying test program:

``` usage: DaemonTest data-directory latitude1 longitude1 latitude2 longitude2 [...latitudeN longitudeN] computes a route using between the specified waypoints

```

To query a route or unpack a MoNavMapModule using the daemon you have to include the signals.h in your project and use it to communicate with the daemon. The test program is a good example on how to do this.

