﻿#ifndef _GROUPCHATSIDEBAR_H_
#define _GROUPCHATSIDEBAR_H_

#include <QFrame>
#include <QTextEdit>
#include <QVector>
#include <vector>
#include <QMutexLocker>
#include "../Message/GroupMessage.h"

class GroupMember;
class GroupTopic;
class GroupChatSidebar : public QFrame
{
	Q_OBJECT
public:
    explicit GroupChatSidebar(QWidget* parent = nullptr);
	~GroupChatSidebar() override;

Q_SIGNALS:
	void deleteMember(const std::string& );
	void updateGroupTopic(const QString&);

public:
	void updateGroupMember(const GroupMemberMessage& e);
	void updateGroupMember(const std::string& memberJid, const std::string& nick, int affiliation);
	void clearData();

private:
	void initUi();

public:
	GroupMember* _pGroupMember;

private:
	GroupTopic*  _pGroupTopic;
	std::vector<std::string> _arMembers;

private:
	QMutex _mutex;
};

#endif//