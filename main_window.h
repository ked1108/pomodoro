//
// Created by kedar on 9/13/24.
//

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H


#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QColor>
#include <QDialog>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>

class SettingsDialog : public QDialog {
    Q_OBJECT

public:
    SettingsDialog(QWidget* parent = nullptr);
    int getDuration() const;
    int getBreakTime() const;
    QColor getProgressColor() const;

    private slots:
        void acceptSettings();

private:
    QSpinBox* durationSpinBox;
    QSpinBox* breakSpinBox;
    int duration;
    int breakTime;
    QColor progressColor;
};


#endif //MAIN_WINDOW_H
