#pragma once

#ifndef TRAYAPP_H
#define TRAYAPP_H
#include <QSystemTrayIcon>

#ifndef QT_NO_SYSTEMTRAYICON

#include <QDialog>
#include <QMenu>
#include <QAction>
#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QTextEdit>

#include "ui_TrayApp.h"

#include "../ControlPanel/ControlPanel.h"

class TrayApp : public QDialog
{
	Q_OBJECT

public:
	TrayApp();
	//void setVisible(bool visible) override;

protected:
	//void closeEvent(QCloseEvent *event) override;

private slots:
	//void setIcon();
	void iconActivated(QSystemTrayIcon::ActivationReason reason);
	void showMessage(string message);
	//void messageClicked();

private:
	void createActions();
	void startMicrophone();
	void stopMicrophone();
	void toggleServiceDiscovery();
	void createTrayIcon();

	QAction* startService;
	QAction* stopService;
	QAction* discoveryToggle;
	QAction* quitAction;

	QSystemTrayIcon* trayIcon;
	QMenu* trayIconMenu;

	ControlPanel* controlPanel;
	bool isMDNSon = false;
	bool isMicrophoneStarted = false;

	QString iconPath = ":/Resources/Assets/icon/1200x630Artboard 10xxhdpi.png";
};


#endif // QT_NO_SYSTEMTRAYICON

#endif // !TRAYAPP_H
