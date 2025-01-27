#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "team.h"
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

private slots:
    void m_plus1(Team &team);
    void m_plus3(Team &team);
    void m_plus5(Team &team);
    void m_set15(Team &team);
    void m_set0(Team &team);
    void m_undo(Team &team);

private:
    void update_score(Team &team);

public:
    Team team1;
    Team team2;
};
#endif // WIDGET_H
