//
// Created by kedar on 9/13/24.
//

#include "pomodoro.h"
#include <QTime>
#include <QProcess>

CircularTimer::CircularTimer(int workDuration, int breakDuration, int sessionCount, QColor workColor, QWidget* parent)
    : QWidget(parent),
    totalTime(workDuration * 60),
    remainingTime(totalTime),
    workTime(workDuration * 60),
    breakTime(breakDuration * 60),
    sessionCount(sessionCount),
    isWorkTimer(true),
    progressColor(workColor){
    this->resize(400, 400);

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &CircularTimer::updateProgress);
    timer->start(1000);
}

void CircularTimer::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QRectF rect(10, 10, width() - 20, height() - 20);
    QPen backgroundPen(QColor(0, 0, 0), 15);
    painter.setPen(backgroundPen);
    painter.drawArc(rect, 0, 360 * 16);

    QPen progressPen(progressColor, 15);
    painter.setPen(progressPen);
    int spanAngle = static_cast<int>((static_cast<double>(remainingTime) / totalTime) * 360.0 * 16);
    painter.drawArc(rect, 90 * 16, -spanAngle);

    QString timeText = QTime(0, remainingTime / 60, remainingTime % 60).toString("mm:ss");
    QFont font("Arial", 20, QFont::Bold);
    painter.setFont(font);

    QRectF textRect = painter.boundingRect(rect, Qt::AlignCenter, timeText);

    painter.setPen(QColor(255, 255, 255));

    painter.drawText(textRect, Qt::AlignCenter, timeText);

    QString sessionText = QString("%1").arg(sessionCount);  // "Session: 1" etc.
    QFont sessionFont("Arial", 14);  // Smaller font for session text
    painter.setFont(sessionFont);
    QRectF sessionTextRect = textRect.translated(0, textRect.height() + 20);  // Move it below the time
    painter.drawText(sessionTextRect, Qt::AlignCenter, sessionText);
}

void CircularTimer::updateProgress() {
    if (remainingTime > 0) {
        remainingTime--;
    } else {
        if (isWorkTimer) {
            notifyTaskDone();
            isWorkTimer = false;
            totalTime = breakTime;
            remainingTime = breakTime;
            progressColor = QColor(255, 0, 0);
            update();
        } else {
            sessionCount++;
            notifyTaskDone();
            isWorkTimer = true;
            totalTime = workTime;
            remainingTime = workTime;
            progressColor = QColor(0, 0, 255);
            update();
        }
    }
    update();
}


void CircularTimer::notifyTaskDone() {
    QProcess::execute("notify-send", QStringList() << "Pomodoro Timer" << ((isWorkTimer) ? "Task completed! Starting break..." : "Break Over Time to start working!"));

}