/*
 *  Copyright (C) 2010 Felix Geyer <debfx@fobos.de>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 or (at your option)
 *  version 3 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KEEPASSX_METADATA_H
#define KEEPASSX_METADATA_H

#include <QtCore/QDateTime>
#include <QtCore/QHash>
#include <QtCore/QPointer>
#include <QtGui/QColor>
#include <QtGui/QImage>

#include "core/Global.h"
#include "core/Uuid.h"

class Database;
class Group;

class Metadata : public QObject
{
    Q_OBJECT

public:
    explicit Metadata(QObject* parent = Q_NULLPTR);

    QString generator() const;
    QString name() const;
    QDateTime nameChanged() const;
    QString description() const;
    QDateTime descriptionChanged() const;
    QString defaultUserName() const;
    QDateTime defaultUserNameChanged() const;
    int maintenanceHistoryDays() const;
    QColor color() const;
    bool protectTitle() const;
    bool protectUsername() const;
    bool protectPassword() const;
    bool protectUrl() const;
    bool protectNotes() const;
    // bool autoEnableVisualHiding() const;
    QImage customIcon(const Uuid& uuid) const;
    bool containsCustomIcon(const Uuid& uuid) const;
    QHash<Uuid, QImage> customIcons() const;
    QList<Uuid> customIconsOrder() const;
    bool recycleBinEnabled() const;
    Group* recycleBin();
    const Group* recycleBin() const;
    QDateTime recycleBinChanged() const;
    const Group* entryTemplatesGroup() const;
    QDateTime entryTemplatesGroupChanged() const;
    const Group* lastSelectedGroup() const;
    const Group* lastTopVisibleGroup() const;
    QDateTime masterKeyChanged() const;
    int masterKeyChangeRec() const;
    int masterKeyChangeForce() const;
    int historyMaxItems() const;
    int historyMaxSize() const;
    QHash<QString, QString> customFields() const;

    static const int DefaultHistoryMaxItems;
    static const int DefaultHistoryMaxSize;

    void setGenerator(const QString& value);
    void setName(const QString& value);
    void setNameChanged(const QDateTime& value);
    void setDescription(const QString& value);
    void setDescriptionChanged(const QDateTime& value);
    void setDefaultUserName(const QString& value);
    void setDefaultUserNameChanged(const QDateTime& value);
    void setMaintenanceHistoryDays(int value);
    void setColor(const QColor& value);
    void setProtectTitle(bool value);
    void setProtectUsername(bool value);
    void setProtectPassword(bool value);
    void setProtectUrl(bool value);
    void setProtectNotes(bool value);
    // void setAutoEnableVisualHiding(bool value);
    void addCustomIcon(const Uuid& uuid, const QImage& icon);
    void removeCustomIcon(const Uuid& uuid);
    void copyCustomIcons(const QSet<Uuid>& iconList, const Metadata* otherMetadata);
    void setRecycleBinEnabled(bool value);
    void setRecycleBin(Group* group);
    void setRecycleBinChanged(const QDateTime& value);
    void setEntryTemplatesGroup(Group* group);
    void setEntryTemplatesGroupChanged(const QDateTime& value);
    void setLastSelectedGroup(Group* group);
    void setLastTopVisibleGroup(Group* group);
    void setMasterKeyChanged(const QDateTime& value);
    void setMasterKeyChangeRec(int value);
    void setMasterKeyChangeForce(int value);
    void setHistoryMaxItems(int value);
    void setHistoryMaxSize(int value);
    void addCustomField(const QString& key, const QString& value);
    void removeCustomField(const QString& key);
    void setUpdateDatetime(bool value);

Q_SIGNALS:
    void nameTextChanged();
    void modified();

private:
    template <class P, class V> bool set(P& property, const V& value);
    template <class P, class V> bool set(P& property, const V& value, QDateTime& dateTime);

    QString m_generator;
    QString m_name;
    QDateTime m_nameChanged;
    QString m_description;
    QDateTime m_descriptionChanged;
    QString m_defaultUserName;
    QDateTime m_defaultUserNameChanged;
    int m_maintenanceHistoryDays;
    QColor m_color;

    bool m_protectTitle;
    bool m_protectUsername;
    bool m_protectPassword;
    bool m_protectUrl;
    bool m_protectNotes;
    // bool m_autoEnableVisualHiding;

    QHash<Uuid, QImage> m_customIcons;
    QList<Uuid> m_customIconsOrder;

    bool m_recycleBinEnabled;
    QPointer<Group> m_recycleBin;
    QDateTime m_recycleBinChanged;
    QPointer<Group> m_entryTemplatesGroup;
    QDateTime m_entryTemplatesGroupChanged;
    QPointer<Group> m_lastSelectedGroup;
    QPointer<Group> m_lastTopVisibleGroup;

    QDateTime m_masterKeyChanged;
    int m_masterKeyChangeRec;
    int m_masterKeyChangeForce;
    int m_historyMaxItems;
    int m_historyMaxSize;

    QHash<QString, QString> m_customFields;

    bool m_updateDatetime;
};

#endif // KEEPASSX_METADATA_H
