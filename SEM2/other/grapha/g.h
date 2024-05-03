#ifndef QTGRAPHS_H
#define QTGRAPHS_H

#include <QWidget>
#include <QMouseEvent>

class QtGraphs : public QWidget
{
    Q_OBJECT

public:
    QtGraphs(QWidget* parent = nullptr);
    ~QtGraphs();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    QPoint m_circleCenter;
    bool m_circlePressed;

    QPoint m_greenCircleCenter;
    bool m_greenCirclePressed;

    QPoint m_blueCircleCenter;
    bool m_blueCirclePressed;
};

#endif // QTGRAPHS_H
