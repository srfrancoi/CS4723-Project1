#include "cs4723-project1.h"

#include <debug.h>

#include <KPluginFactory>

K_PLUGIN_FACTORY_WITH_JSON(CS4723_Project1Factory, "cs4723-project1.json", registerPlugin<CS4723_Project1>(); )

CS4723_Project1::CS4723_Project1(QObject* parent, const KPluginMetaData& metaData, const QVariantList& args)
    : KDevelop::IPlugin(QStringLiteral("cs4723-project1"), parent, metaData)
{
    Q_UNUSED(args);

    qCDebug(PLUGIN_CS4723_PROJECT1) << "Hello world, my plugin is loaded!";
}

// needed for QObject class created from K_PLUGIN_FACTORY_WITH_JSON
#include "cs4723-project1.moc"
#include "moc_cs4723-project1.cpp"
