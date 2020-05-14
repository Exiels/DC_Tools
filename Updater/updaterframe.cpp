#include "updaterframe.h"

UpdaterFrame::UpdaterFrame()
{
    resize(200, 100);
    setWindowTitle("DC_Tools Updater");
    setWindowIcon(QIcon("icone.png"));
    progression = new QProgressBar();
}
