#include "termometro.h"
#include "ui_termometro.h"

Termometro::Termometro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Termometro)
{
    ui->setupUi(this);
    connect(ui->cmdCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2Fahr(int)));
    //Connectar dialFahr --->
    connect(ui->cmdFahr, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2Cent(int)));
    //Connectar dialFahr --->
    connect(ui->cmdKelvi, SIGNAL(valueChanged(int)),
            this, SLOT(cent2Kelvin(int)));
}

Termometro::~Termometro()
{
    delete ui;
}

void Termometro::cent2Fahr(int valor)
{
    if(ui->cmdCent->hasFocus()){
        float f = valor * 9.0/5 + 32;
        ui->cmdFahr->setValue(f);
        float t = valor + 273.15;
        ui->cmdKelvi->setValue(t);
    }
}

void Termometro::fahr2Cent(int valor)
{
    if(ui->cmdFahr->hasFocus()){
        float c = (valor - 32) * 5.0/9;
        ui->cmdCent->setValue(c);
        float r = (valor - 32) * 5.0/9 + 273.15;
        ui->cmdKelvi->setValue(r);
    }
}

void Termometro::cent2Kelvin(int valor)
{
    float r = (valor -273.15);
    ui->cmdCent->setValue(r);
    float l = (valor - 273.15) * 9.0/5 + 32;
    ui->cmdFahr->setValue(l);
}

