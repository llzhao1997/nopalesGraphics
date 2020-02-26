#include "nopalesgraphics.h"
#include "ui_nopalesgraphics.h"
#include <QKeyEvent>


#include "view2widget.h"


#include "camera.h"




nopalesGraphics::nopalesGraphics(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::nopalesGraphics )

{

    ui->setupUi(this);
    ui->widget1->update();
    Example = new example();
   // connect(pChild,SIGNAL(buttonClick()),this, SLOT(onChildOk()))
    connect(this,SIGNAL(sendMessage(QString)),Example,SLOT(receiveMessage(QString)));
}





nopalesGraphics::~nopalesGraphics()
{
    delete ui;
}


void nopalesGraphics::on_views_clicked()
{

     QString msg;

      if (msg!=QString::number(ui->widget1->figure)){
          msg = QString::number(ui->widget1->figure);
      }
      emit sendMessage(msg);
      Example ->show();
}




void nopalesGraphics::mouseDoubleClickEvent(QMouseEvent *event)
{

    onMouseEvent("Double Click", event->pos());
    QWidget::mouseDoubleClickEvent(event);

}

void nopalesGraphics::mouseMoveEvent(QMouseEvent *event)
{
    onMouseEvent("mouse Click", event->pos());
    QWidget::mouseMoveEvent(event);

}

void nopalesGraphics::mousePressEvent(QMouseEvent *event)
{

    onMouseEvent("mouse Press", event->pos());
    QWidget::mousePressEvent(event);

}

void nopalesGraphics::mouseReleaseEvent(QMouseEvent *event)
{

    onMouseEvent("mouse Release", event->pos());
    QWidget::mouseReleaseEvent(event);

}

void nopalesGraphics::keyPressEvent(QKeyEvent *e)
{
    cmd = char (e->key());
}



void nopalesGraphics:: onMouseEvent(const QString & eventName,const QPoint & pos)
{
   // ui->spinBox_x->setValue(pos.x());

    if ("#"==cmd){
        ui->widget1->eX=pos.x();
        ui->widget1->eY=pos.y();

        ui->widget1->update();
        ui->views->update();
     }

}

void nopalesGraphics::on_spinBox_x_valueChanged(int arg1)
{
    //lx=ui->spinBox_x->value();
    ui->widget1->lx=ui->spinBox_x->value();
    ui->widget1->update();
    //ui->spinBox_x->setValue(lx);
}

void nopalesGraphics::on_spinBox_y_valueChanged(int arg1)
{

    ui->widget1->ly=ui->spinBox_y->value();
    ui->widget1->update();
}



void nopalesGraphics::on_spinBox_z_valueChanged(int arg1)
{
    ui->widget1->lz=ui->spinBox_z->value();
    ui->widget1->update();
}

void nopalesGraphics::on_spinBox_eX_valueChanged(int arg1)
{
    ui->widget1->eX=ui->spinBox_eX->value();
    ui->widget1->update();
}

void nopalesGraphics::on_spinBox_eY_valueChanged(int arg1)
{
    ui->widget1->eY=ui->spinBox_eY->value();
    ui->widget1->update();
}

void nopalesGraphics::on_spinBox_eZ_valueChanged(int arg1)
{
    ui->widget1->eZ=ui->spinBox_eZ->value();
    ui->widget1->update();
}




void nopalesGraphics::on_add_point_clicked()
{

     ui->widget1->add_px  = (ui->ispinbox->toPlainText()).toInt();
     ui->widget1->add_py =  (ui->ispinboy->toPlainText()).toInt();
     ui->widget1->add_pz =  (ui->ispinboz->toPlainText()).toInt();
     ui->widget1->update();

}






void nopalesGraphics::on_buttonPlay_clicked()
{

}

void nopalesGraphics::on_actionSplineA_triggered()
{
    ui->widget1->figure=1;
    ui->widget1->update();

}

void nopalesGraphics::on_actionSplineB_triggered()
{
    ui->widget1->figure=2;
    ui->widget1->update();
}

void nopalesGraphics::on_actionSplineC_triggered()
{
    ui->widget1->figure=3;
    ui->widget1->update();
}

void nopalesGraphics::on_actionNurbsA_triggered()
{
    ui->widget1->figure=4;
    ui->widget1->update();

}

void nopalesGraphics::on_actionCube_triggered()
{
    ui->widget1->figure=7;
    ui->widget1->update();
}

void nopalesGraphics::on_actionNew_Animation_triggered()
{

}
