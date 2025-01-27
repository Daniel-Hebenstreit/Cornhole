#ifndef TEAM_H
#define TEAM_H

#include <QObject>

class Team : public QObject
{
    Q_OBJECT
public:
    explicit Team(QObject *parent = nullptr);

public:
    int m_score[2] = {0, 0};

};

#endif // TEAM_H
