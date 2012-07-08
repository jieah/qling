/* Copyright (C) 2006 - 2011 Thomas Gahr <thomas.gahr@physik.uni-muenchen.de>

   This file is part of the Trojita Qt IMAP e-mail client,
   http://trojita.flaska.net/

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or the version 3 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef CODEINPUT_H
#define CODEINPUT_H

#include <QLineEdit>
#include <QStringList>

/** LineEdit that keeps a history of stuff entered
  *
  * history is saved via the QSettings interface so use
  * QApplication::setApplicationName and QApplication::setOrganizationName
  * to uniquely identify the settings
  */
class CodeInput : public QLineEdit
{
    Q_OBJECT
public:
    explicit CodeInput(QWidget *parent = 0);
    ~CodeInput();

    bool eventFilter(QObject *, QEvent *);

    /** set maximum number of entries in history.
      *
      * Default: 50
      * Note: The current history - if longer than s - will not be truncated
      * until the next entry is added
      */
    void setMaxHistorySize(int s);
    int maxHistorySize()const;

signals:
    void entered(const QString& str);

public slots:

private:
    //might be public???
    void addToHistory(const QString& str);
    void moveInHistory(int dir);
    QStringList m_history;
    int m_historyPos;
    int m_maxHistorySize;
};

#endif // CODEINPUT_H
