/*
Copyright 2010  Christian Vetter veaac.fdirct@gmail.com

This file is part of MoNav.

MoNav is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

MoNav is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with MoNav.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QtGui/QApplication>
#include "mainwindow.h"
#include "mapdata.h"
#include "routinglogic.h"
#include "logger.h"
#include <QMessageBox>
#include <QtPlugin>
#include <QThread>
#include <cstdio>
#include <cstdlib>

#ifdef Q_WS_MAEMO_5
	#include <QMaemo5InformationBox>
#endif

Q_IMPORT_PLUGIN( mapnikrendererclient );
Q_IMPORT_PLUGIN( contractionhierarchiesclient );
Q_IMPORT_PLUGIN( gpsgridclient );
Q_IMPORT_PLUGIN( unicodetournamenttrieclient );
Q_IMPORT_PLUGIN( osmrendererclient );
Q_IMPORT_PLUGIN( qtilerendererclient );


void MessageBoxHandler(QtMsgType type, const char *msg)
{
	if ( QApplication::instance() != NULL ) {
		const bool isGuiThread = QThread::currentThread() == QApplication::instance()->thread();
		if ( isGuiThread ) {
	#ifdef Q_WS_MAEMO_5
			switch (type) {
			case QtDebugMsg:
				//QMessageBox::information(0, "Debug message", msg, QMessageBox::Ok);
				break;
			case QtWarningMsg:
				QMaemo5InformationBox::information( NULL, msg, QMaemo5InformationBox::NoTimeout );
				break;
			case QtCriticalMsg:
				QMaemo5InformationBox::information( NULL, msg, QMaemo5InformationBox::NoTimeout );
				break;
			case QtFatalMsg:
				QMaemo5InformationBox::information( NULL, msg, QMaemo5InformationBox::NoTimeout );
				exit( -1 );
			}
	#else
			switch (type) {
			case QtDebugMsg:
				//QMessageBox::information(0, "Debug message", msg, QMessageBox::Ok);
				break;
			case QtWarningMsg:
				QMessageBox::warning(0, "Warning", msg, QMessageBox::Ok);
				break;
			case QtCriticalMsg:
				QMessageBox::critical(0, "Critical error", msg, QMessageBox::Ok);
				break;
			case QtFatalMsg:
				QMessageBox::critical(0, "Fatal error", msg, QMessageBox::Ok);
				exit( -1 );
			}
	#endif
		}
	}

	printf( "%s\n", msg );
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qInstallMsgHandler( MessageBoxHandler );
	a.connect( &a, SIGNAL(aboutToQuit()), MapData::instance(), SLOT(cleanup()) );
	a.connect( &a, SIGNAL(aboutToQuit()), RoutingLogic::instance(), SLOT(cleanup()) );
	a.connect( &a, SIGNAL(aboutToQuit()), Logger::instance(), SLOT(cleanup()) );
	MainWindow w;
	w.show();
	return a.exec();
}
