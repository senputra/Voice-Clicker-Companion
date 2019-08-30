#include "TrayApp.h"


TrayApp::TrayApp()
{
	controlPanel = new ControlPanel();

	createActions();
	createTrayIcon();
	trayIcon->show();


	trayIcon->setIcon(QIcon(iconPath));
	trayIcon->setToolTip(QString::fromStdString("Voice Clicker"));

	connect(trayIcon, &QSystemTrayIcon::activated, this, &TrayApp::iconActivated);

	QDialog::setVisible(false);
}

void TrayApp::showMessage(string message)
{
	trayIcon->showMessage("Voice Clicker PC", message.c_str(), QIcon(iconPath),
		5 * 1000);
}

/// This function is called when the tray icon is clicked or something else;
void TrayApp::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason) {
	case QSystemTrayIcon::Trigger: break; // Left Click
	case QSystemTrayIcon::DoubleClick: // Double Left Click
		/*iconComboBox->setCurrentIndex((iconComboBox->currentIndex() + 1) % iconComboBox->count());*/
		break;
	case QSystemTrayIcon::MiddleClick: // Middle Click
		//showMessage();
		break;
	default:
		;
	}
}

void TrayApp::createActions() {
	startService = new QAction(tr("St&art Service"), this);
	connect(startService, &QAction::triggered, this, &TrayApp::startMicrophone);

	stopService = new QAction(tr("St&op Service"), this);
	connect(stopService, &QAction::triggered, this, &TrayApp::stopMicrophone);
	stopService->setDisabled(true);

	discoveryToggle = new QAction(tr("Discover On"), this);
	connect(discoveryToggle, &QAction::triggered, this, &TrayApp::toggleServiceDiscovery);

	quitAction = new QAction(tr("&Quit"), this);
	connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
}
void TrayApp::startMicrophone() {
	isMicrophoneStarted = true;
	controlPanel->startMicrophone();
	showMessage("Voice CLicker has started");
	stopService->setDisabled(false);
	startService->setDisabled(true);
}

void TrayApp::stopMicrophone() {
	isMicrophoneStarted = false;
	controlPanel->stopMicrophone();
	showMessage("Voice Clicker has stopped");
	stopService->setDisabled(true);
	startService->setDisabled(false);
}

void TrayApp::toggleServiceDiscovery() {
	if (!isMicrophoneStarted) {
		showMessage("Please start service first before clicking Discover");
		return;
	}
	if (isMDNSon) {
		discoveryToggle->setText("Discover On");
		isMDNSon = false;
		controlPanel->stopServiceAdvertising(); return;
	}
	discoveryToggle->setText("Discover Off");
	isMDNSon = true;
	controlPanel->startServiceAdvertising(); return;

}
void TrayApp::createTrayIcon()
{
	trayIconMenu = new QMenu(this);
	trayIconMenu->addAction(startService);
	trayIconMenu->addAction(stopService);
	trayIconMenu->addAction(discoveryToggle);
	trayIconMenu->addSeparator();
	trayIconMenu->addAction(quitAction);

	trayIcon = new QSystemTrayIcon(this);
	trayIcon->setContextMenu(trayIconMenu);
}

