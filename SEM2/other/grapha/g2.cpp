#include "QtGraphs.h"
#include <QPainter>

QtGraphs::QtGraphs(QWidget* parent)
    : QWidget(parent)
{
    m_circleCenter = QPoint(100, 100); // Начальные координаты центра круга
    m_circlePressed = false;
    m_blueCircleCenter = m_greenCircleCenter = m_circleCenter;
}
QtGraphs::~QtGraphs()
{
}

void QtGraphs::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QFont font = painter.font();
    font.setPointSize(16); // Устанавливаем размер шрифта 16
    painter.setFont(font);
    

    painter.setBrush(Qt::red);
    painter.drawEllipse(m_circleCenter, 20, 20);

    painter.setBrush(Qt::green);
    painter.drawEllipse(m_greenCircleCenter, 20, 20);

    painter.setBrush(Qt::blue);
    painter.drawEllipse(m_blueCircleCenter, 20, 20);

    painter.drawText(m_circleCenter, "1");
    painter.drawText(m_greenCircleCenter, "2");
    painter.drawText(m_blueCircleCenter, "3");

    painter.drawLine(m_circleCenter, m_greenCircleCenter);
    painter.drawLine(m_greenCircleCenter, m_blueCircleCenter);
    painter.drawLine(m_blueCircleCenter, m_circleCenter);
}

void QtGraphs::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        if ((event->pos() - m_circleCenter).manhattanLength() < 50) {
            m_circlePressed = true;
        }
        else if ((event->pos() - m_greenCircleCenter).manhattanLength() < 50) {
            m_greenCirclePressed = true;
        }
        else if ((event->pos() - m_blueCircleCenter).manhattanLength() < 50) {
            m_blueCirclePressed = true;
        }
    }
}

void QtGraphs::mouseMoveEvent(QMouseEvent* event)
{
    if (m_circlePressed) {
        m_circleCenter = event->pos();
    }
    else if (m_greenCirclePressed) {
        m_greenCircleCenter = event->pos();
    }
    else if (m_blueCirclePressed) {
        m_blueCircleCenter = event->pos();
    }

    update();
}

void QtGraphs::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        m_circlePressed = false;
        m_greenCirclePressed = false;
        m_blueCirclePressed = false;
    }
}
