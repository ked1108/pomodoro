//
// Created by kedar on 9/13/24.
//

#ifndef POMODORO_H
#define POMODORO_H



#include <QWidget>
#include <QPainter>
#include <QTimer>

class CircularTimer : public QWidget {
    Q_OBJECT

public:
    CircularTimer(int duration = 25, int breakTime = 5, int sessionCount = 1, QColor color = QColor(0, 0, 255), QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;
    void notifyTaskDone();

    private slots:
        void updateProgress();

private:
    int totalTime;
    int remainingTime;
    int breakTime;
    int workTime;
    int sessionCount;
    bool isWorkTimer;
    QColor progressColor;
};
#endif //POMODORO_H
