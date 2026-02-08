/* This file is part of the KDE project
    SPDX-FileCopyrightText: 2006 David Faure <faure@kde.org>

    SPDX-License-Identifier: GPL-2.0-or-later
*/

#ifndef KONQVIEWMGRTEST_H
#define KONQVIEWMGRTEST_H

#include <QObject>

class WebEnginePart;

class ViewMgrTest : public QObject
{
    Q_OBJECT

    /**
     * @brief Attempts to simulate a mouse click on a link on the page loaded in the given WebEnginePart
     *
     * It assumes that the link has id `linkid`.
     *
     * @warning The mouse click is simulated using javascript and not `QTest::mouseClick()` or similar, because
     * it looks like using them to click on a link doesn't work if the view isn't visible.
     *
     * @param part the part containing the page with the link to click
     * @param btn the mouse button to simulate
     * @param modifiers the keyboard modifiers
     * @param timeout the time to wait before considering the link attempt failed
     * @return `true` if the click simulation succeeded and `false` otherwise
     */
    static bool simulateClick(WebEnginePart *part, Qt::MouseButton btn = Qt::LeftButton, Qt::KeyboardModifiers modifiers = {}, int timeout = 500);

    static void resetSettings();

private Q_SLOTS:
    void initTestCase();
    void init();

    void testCloseOtherTabs();
    void testCloseTabsFast();
    void testCreateFirstView();
    void testEmptyWindow();
    void testRemoveFirstView();
    void testSplitView();
    void testSplitMainContainer();
    void testLinkedViews();

    void testPopupNewTab();
    void testPopupNewWindow();
    void testCtrlClickOnLink();
    void sameTestsWithNewTabsInFront();
    void sameTestsWithMmbOpenTabsFalse();

    void testAddTabs();
    void testDuplicateTab();
    void testDuplicateSplittedTab();
    void testDeletePartInTab();
    void testSaveProfile();

    void testDuplicateWindow();

    void testBrowserArgumentsNewTab();

    void testBreakOffTab();
    void moveTabLeft();

    static void sendAllPendingResizeEvents(QWidget *);
};

#endif
