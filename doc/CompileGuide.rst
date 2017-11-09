Introduction
++++++++++++

Compiling the client application is fairly easy as it only depends on Qt. The preprocessor application on the other hand has more dependencies.

Details
+++++++

Version 0.3 source code

https://monav.googlecode.com/svn/tags/release-0.3

Dependencies
++++++++++++

Client
------

Qt-4
Qt-Mobility

Routing Daemon
--------------

Qt-4

Preprocessor
------------

Qt-4
Mapnik
libxml2
libbz2
libprotobuf
protobuf-compiler

Linux
+++++

Qt, libxml2, libbz2, protobuffer and mapnik should be available
Only tested with gcc > 4.4.2
Compile client / preprocessor-gui:
release: qmake CONFIG+=release monav-client.pro && make
debug: qmake CONFIG+=debug monav-client.pro && make
Compile console preprocessor / routing daemon:
release: qmake CONFIG+=release CONFIG+=nogui X.pro && make
debug: qmake CONFIG+=debug CONFIG+=nogui X.pro && make

Windows / Windows Mobile
++++++++++++++++++++++++

Some Visual Studio version define a max/min macro. This breaks MoNav. If you encounter releated compiling issues try to append DEFINES+=NOMINMAX to the qmake command line.

Client:
Install Visual Studio 2005 / 2008
Download / compile Qt and Qt-Mobility binaries. A static build is recommended for Windows Mobile as each application has only 32MB virtual address space
Compile client:
release: qmake CONFIG+=release monav-client.pro && nmake
debug: qmake CONFIG+=debug monav-client.pro && nmake
Routing Daemon:
Compile routing daemon:
release: qmake CONFIG+=release CONFIG+=nogui X.pro && mmake
debug: qmake CONFIG+=debug CONFIG+=nogui X.pro && mmake

Maemo & Symbian
+++++++++++++++

The easiest way to build for those platforms is to use the QtCreator. Just open the .pro file and add the desired platform as a target. Maemo is supported officially, but Symbian is not.

Android
+++++++

While it is possible to build MoNav for Android, it is not supported right now ( the SVN contains build scripts, though ).
