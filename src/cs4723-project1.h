#ifndef CS4723_PROJECT1_H
#define CS4723_PROJECT1_H

#include <interfaces/iplugin.h>

class CS4723_Project1 : public KDevelop::IPlugin
{
    Q_OBJECT

public:
    // KPluginFactory-based plugin wants constructor with this signature
    CS4723_Project1(QObject* parent, const KPluginMetaData& metaData, const QVariantList& args);
};

#endif // CS4723_PROJECT1_H
