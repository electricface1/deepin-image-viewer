/*
 * Copyright (C) 2016 ~ 2017 Deepin Technology Co., Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "slider.h"
#include "utils/baseutils.h"
#include <QMouseEvent>

Slider::Slider(QWidget *parent)
    : QSlider(parent)
{
//    setStyleSheet(utils::base::getFileContent(":/qss/resources/qss/Slider.qss"));
}

Slider::Slider(Qt::Orientation orientation, QWidget *parent)
    :QSlider(orientation, parent)
{
//    setStyleSheet(utils::base::getFileContent(":/qss/resources/qss/Slider.qss"));
}

void Slider::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        double dv = 0;
        if (orientation() == Qt::Vertical)
            dv = ((maximum()-minimum()) * (height()- e->y()) * 1.0) / height();
        else
            dv = ((maximum()-minimum()) * e->x() * 1.0) / width();
        setValue(minimum() + qRound(dv)) ;

        e->accept();
    }
    QSlider::mousePressEvent(e);
}
