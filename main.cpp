#include <QApplication>
#include "main_window.h"
#include "pomodoro.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    app.setStyleSheet("QWidget { background-color: black; color: white; }");

    SettingsDialog settingsDialog;
    if (settingsDialog.exec() == QDialog::Accepted) {

        int duration = settingsDialog.getDuration();
        int breakTime = settingsDialog.getBreakTime();
        QColor color = settingsDialog.getProgressColor();

        CircularTimer timer(duration, breakTime, 0, color);
        timer.resize(200, 200);  // Set size of the widget
        timer.show();

        return app.exec();
    }

    return 0;
}
