#include "widget.h"
#include "ui_widget.h"
#include "team.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Team 1 Signal Slot Connection
    connect(ui->btn_plus1_t1, &QPushButton::clicked, this, [=](){ m_plus1(team1); });
    connect(ui->btn_plus3_t1, &QPushButton::clicked, this, [=](){ m_plus3(team1); });
    connect(ui->btn_plus5_t1, &QPushButton::clicked, this, [=](){ m_plus5(team1); });
    connect(ui->btn_set15_t1, &QPushButton::clicked, this, [=](){ m_set15(team1); });
    connect(ui->btn_set0_t1, &QPushButton::clicked, this, [=](){ m_set0(team1); });
    connect(ui->btn_undo_t1, &QPushButton::clicked, this, [=](){ m_undo(team1); });

    // Team 2 Signal Slot Connection
    connect(ui->btn_plus1_t2, &QPushButton::clicked, this, [=](){ m_plus1(team2); });
    connect(ui->btn_plus3_t2, &QPushButton::clicked, this, [=](){ m_plus3(team2); });
    connect(ui->btn_plus5_t2, &QPushButton::clicked, this, [=](){ m_plus5(team2); });
    connect(ui->btn_set15_t2, &QPushButton::clicked, this, [=](){ m_set15(team2); });
    connect(ui->btn_set0_t2, &QPushButton::clicked, this, [=](){ m_set0(team2); });
    connect(ui->btn_undo_t2, &QPushButton::clicked, this, [=](){ m_undo(team2); });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::update_score(Team &team)
{
    if (&team == &team1)
    {
        ui->label_score_team1->setText(QString::number(team1.m_score[1]));
        ui->btn_undo_t1->setDisabled(0);
    }
    else
    {
        ui->label_score_team2->setText(QString::number(team2.m_score[1]));
        ui->btn_undo_t2->setDisabled(0);
    }
}

void Widget::m_plus1(Team &team)
{
    team.m_score[0] = team.m_score[1];
    team.m_score[1] +=1;
    update_score(team);
}

void Widget::m_plus3(Team &team)
{
    team.m_score[0] = team.m_score[1];
    team.m_score[1] +=3;
    update_score(team);
}

void Widget::m_plus5(Team &team)
{
    team.m_score[0] = team.m_score[1];
    team.m_score[1] +=5;
    update_score(team);
}

void Widget::m_set15(Team &team)
{
    team.m_score[0] = team.m_score[1];
    team.m_score[1] = 15;
    update_score(team);
}

void Widget::m_set0(Team &team)
{
    team.m_score[0] = team.m_score[1];
    team.m_score[1] = 0;
    update_score(team);
}

void Widget::m_undo(Team &team)
{
    team.m_score[1] = team.m_score[0];
    update_score(team);

    if (&team == &team1)
        ui->btn_undo_t1->setDisabled(1);
    else
        ui->btn_undo_t2->setDisabled(1);

}

