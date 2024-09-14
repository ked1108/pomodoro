//
// Created by kedar on 9/13/24.
//

#include "main_window.h"
#include <QVBoxLayout>
#include <QColorDialog>
#include <QLabel>

SettingsDialog::SettingsDialog(QWidget* parent)
    : QDialog(parent), duration(25),breakTime(5), progressColor(QColor(0, 0, 255)) {
    setWindowTitle("Timer Settings");
    this->setFixedSize(400, 300);

    QLabel* workDurationLabel = new QLabel("Work Duration (minutes)", this);
    durationSpinBox = new QSpinBox(this);
    durationSpinBox->setRange(1, 120);
    durationSpinBox->setValue(25);  // Default is 25 minutes

    QLabel* breakDurationLabel = new QLabel("Break Duration (minutes)", this);
    breakSpinBox = new QSpinBox(this);
    breakSpinBox->setRange(1, 60);
    breakSpinBox->setValue(5);

    QPushButton* okButton = new QPushButton("Start Sessions", this);
    okButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    okButton->setStyleSheet("padding: 10px;");

    connect(okButton, &QPushButton::clicked, this, &SettingsDialog::acceptSettings);

    // Layout setup
    QHBoxLayout* workLayout = new QHBoxLayout();
    workLayout->addWidget(workDurationLabel);
    workLayout->addWidget(durationSpinBox);

    // Layout setup for Break Timer
    QHBoxLayout* breakLayout = new QHBoxLayout();
    breakLayout->addWidget(breakDurationLabel);
    breakLayout->addWidget(breakSpinBox);

    // Main layout setup
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* controlsLayout = new QHBoxLayout();
    controlsLayout->addStretch();
    QVBoxLayout* optionsLayout = new QVBoxLayout();
    optionsLayout->addStretch();

    optionsLayout->addLayout(workLayout);
    optionsLayout->addLayout(breakLayout);
    optionsLayout->addStretch();

    controlsLayout->addLayout(optionsLayout);
    controlsLayout->addStretch();

    mainLayout->addLayout(controlsLayout);
    mainLayout->addWidget(okButton, 0, Qt::AlignCenter);

    setLayout(mainLayout);
}

void SettingsDialog::acceptSettings() {
    duration = durationSpinBox->value();
    breakTime = breakSpinBox->value();
    progressColor = QColor(0, 0, 255);
    accept();
}

int SettingsDialog::getDuration() const {
    return duration;
}

int SettingsDialog::getBreakTime() const {
    return breakTime;
}

QColor SettingsDialog::getProgressColor() const {
    return progressColor;
}