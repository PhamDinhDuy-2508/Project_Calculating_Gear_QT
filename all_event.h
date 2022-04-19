#ifndef ALL_EVENT_H
#define ALL_EVENT_H
#include<QStyledItemDelegate>
class All_Event
{
public:
    All_Event();
};
class FilterDelegate : public QStyledItemDelegate
{
public:
    FilterDelegate(QObject *filter, QObject *parent = 0) :
        QStyledItemDelegate(parent), filter(filter)
    { }

    virtual QWidget *createEditor(QWidget *parent,
                                  const QStyleOptionViewItem &option,
                                  const QModelIndex &index) const
    {
        QWidget *editor = QStyledItemDelegate::createEditor(parent, option, index);
        editor->installEventFilter(filter);
        return editor;
    }

private:
    QObject *filter;
};

#endif // ALL_EVENT_H
