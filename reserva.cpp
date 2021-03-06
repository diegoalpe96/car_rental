#include "reserva.h"

Reserva::Reserva()
{

    _inicio = QDateTime();
    _matricula = "";
    _id ="";
    _fin = QDateTime();

}
Reserva::Reserva(const string &id , QDateTime inicio , QDateTime fin , const string & matricula)
{

    QDateTime _inicio(inicio);
    QDateTime _fin(fin);
    _id               =   id;
    _matricula        =   matricula;

}
QDateTime Reserva::getInicio()
{
    return _inicio;
}
void Reserva::setInicio(QDateTime inicio)
{
    _inicio = inicio;
}
QDateTime Reserva::getFin()
{
    return _fin;

}
void Reserva::setFin(QDateTime fin)
{
    _fin = fin;

}


Reserva & Reserva::operator=(Reserva reserva)
{
    _inicio          = reserva._inicio;
    _fin             = reserva._fin;
    _matricula       = reserva._matricula;
    _id              = reserva._id;

    return *this;
}

Reserva::~Reserva()
{

}
float Reserva::precioReserva(QDateTime inicio, QDateTime fin)
{
    int segundos = inicio.secsTo(fin);
    float prize = segundos * 0.19/60;
    return prize;
}

void Reserva::pideFecha()
{   char opcion;
    cout<<"Elija una fecha para el inicio"<<endl;
    QDateTime inicio;
    QDateTime final;
    do{
        cout<<"¿Desea reservarlo para ahora mismo? (S o N)"<<endl;
        cin>>opcion;
        if (opcion=='S'||opcion=='s')
        _inicio=QDateTime::currentDateTime();
        else if(opcion=='N'||opcion=='n')
        {
            int fecha[5];
            do{
                cout<<"Escriba el ano en el que INICIAR la reserva."<<endl;
                cin>>fecha[0];
                cout<<"Escriba el mes, (1-12) en el que INICIAR la reserva."<<endl;
                cin>>fecha[1];
                cout<<"Escriba el dia (1-30/31) en el que INICIAR la reserva."<<endl;
                cin>>fecha[2];
                cout<<"Escriba la hora, (0-23) en el que INICIAR la reserva."<<endl;
                cin>>fecha[3];
                cout<<"Escriba el minuto, (0-59) en el que INICIAR la reserva."<<endl;
                cin>>fecha[4];
                QDateTime ini(QDate(fecha[0],fecha[1],fecha[2]),QTime(fecha[3],fecha[4],0,0));
                inicio=ini;
            }while(!inicio.isValid() || inicio<QDateTime::currentDateTime());

        }


    }while(opcion!='s' && opcion!='S' && opcion!='n' && opcion!='N');


    int fecha[5];
    do{
        cout<<"Escriba el ano en el que FINALIZAR la reserva."<<endl;
        cin>>fecha[0];
        cout<<"Escriba el mes, (1-12) en el que FINALIZAR la reserva."<<endl;
        cin>>fecha[1];
        cout<<"Escriba el dia, (1-30/31) en el que FINALIZAR la reserva."<<endl;
        cin>>fecha[2];
        cout<<"Escriba la hora, (0-23) en el que FINALIZAR la reserva."<<endl;
        cin>>fecha[3];
        cout<<"Escriba el minuto, (0-59) en el que FINALIZAR la reserva."<<endl;
        cin>>fecha[4];
        QDateTime fin(QDate(fecha[0],fecha[1],fecha[2]),QTime(fecha[3],fecha[4],0,0));
        final=fin;
    }while(!final.isValid() || final<inicio);

    _inicio = inicio;
    _fin = final;

    QString iTime = inicio.toString("HH:mm:ss 'of' dddd dd 'of' MMMM 'of' yyyy");
    cout<<"Hora inicio -->  "<<iTime.toStdString()<<endl<<endl;
    QString fTime = final.toString("HH:mm:ss 'of' dddd dd 'of' MMMM 'of' yyyy");
    cout<<"Hora fin -->  "<<fTime.toStdString()<<endl<<endl;
    cout<<"El coste de la operacion asciende a "<< precioReserva(inicio, final)<<" Euros"<<endl<<endl;

}
