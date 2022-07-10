#include <iostream>
#include <boost/asio.hpp>
#include <QApplication>
#include <QWidget>
#include <QtPlugin>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QComboBox>
#include <QPushButton>

Q_IMPORT_PLUGIN (QWindowsIntegrationPlugin);

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget *firstPageWidget = new QWidget;
    QWidget *secondPageWidget = new QWidget;
    QWidget *thirdPageWidget = new QWidget;

    QStackedWidget *stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(firstPageWidget);
    stackedWidget->addWidget(secondPageWidget);
    stackedWidget->addWidget(thirdPageWidget);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(stackedWidget);

    QComboBox *pageComboBox = new QComboBox;
    pageComboBox->addItem(QPushButton::tr("Page 1"));
    pageComboBox->addItem(QPushButton::tr("Page 2"));
    pageComboBox->addItem(QPushButton::tr("Page 3"));

    app.setActiveWindow(stackedWidget);

    return app.exec();
}
