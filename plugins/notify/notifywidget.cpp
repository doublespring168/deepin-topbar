#include "notifywidget.h"
#include "fontlabel.h"
#include <QIcon>
#include <QHBoxLayout>
#include <QEvent>
#include <QMouseEvent>

NotifyWidget::NotifyWidget(QWidget *parent) : QLabel(parent)
{
      setFixedSize(25, 25);

      setStyleSheet("QLabel {"
                    "background: transparent;"
                    "}"
                    "QLabel:hover {"
                    "background: #1E90FF;"
                    "}");

      m_NotifyIcon = new FontLabel;
      m_NotifyIcon->setFixedSize(22, 22);
      m_NotifyIcon->setIcon(QChar(0xE7E7), 16);

      QHBoxLayout *layout = new QHBoxLayout;

      layout->setMargin(0);
      layout->setSpacing(0);
      layout->addWidget(m_NotifyIcon, 0, Qt::AlignCenter);

      setLayout(layout);

      installEventFilter(this);
}

bool NotifyWidget::eventFilter(QObject *watched, QEvent *event)
{
    Q_UNUSED(watched);

    if (event->type() == QMouseEvent::Enter) {
        m_NotifyIcon->setStyleSheet("background: transparent;"
                                    "color: white;");
    }

    if (event->type() == QMouseEvent::Leave) {
        m_NotifyIcon->setStyleSheet("background: transparent;"
                                    "color: black;");
    }

    return false;
}
