#ifndef DATASTORAGE_H
#define DATASTORAGE_H


#include <QMap>

struct TData{
QString part;
int counts; //кол-во
QString notes;     //примечания
};

struct dataStorage{
private:
    QMap <QString, QList<TData>> storage_;
public:

    void insert(QString refDez, QString partNum, int qty  ){

        //Входные данные могут быть C1-C8 или C1, C2
        QString refDez_ = refDez;
        int c = refDez.indexOf(",");
        if(c > 0){
            refDez.remove(c, refDez.count() - c);
        }
        c = refDez.indexOf("-");
        if(c > 0){
            refDez.remove(c, refDez.count() - c);
        }
        refDez.remove(QRegExp("[^A-Za-zА-Яа-я]"));
        // Есть ли такой ключ?
        bool keyF = false;
        foreach (auto var, storage_.keys()) {
            if( var == refDez){
                keyF = true;
                break;
            }
        }
        int k = 0; // для отладки
//------Такой ключ уже существует
        if(keyF == true){
            bool PartNumbF = false;
//---#------есть ли такой partNumber?
            for (int i = 0; i < storage_[refDez].count(); i++) {
                QString a = storage_[refDez].at(i).part;
                if( a == partNum){
                    storage_[refDez][i].counts += qty;
                    storage_[refDez][i].notes.append("," + refDez_);
                    PartNumbF = true;
                }
            }
//---#------такого partNumber'а нет
            if( PartNumbF == false ){
                QList<TData> bomNumb;
                TData strAndNumb;
                strAndNumb.part = partNum;
                strAndNumb.notes = refDez_;
                strAndNumb.counts = qty;
                bomNumb << strAndNumb;
                storage_[refDez].append(bomNumb);
            }
        }

//------такого ключа нет
        else{
            QList<TData> bomNumb;
            TData strAndNumb;
            strAndNumb.part = partNum;
            strAndNumb.notes = refDez_;
            strAndNumb.counts = qty;
            bomNumb << strAndNumb;
            storage_.insert(refDez,bomNumb );

        }
        //storage_.insert(refDez, )
    }
    QMap <QString, QList<TData> >  ret() {
        foreach (QString var, storage_.keys()) {
            //сколько QList<TData>
            for (int i = 0; i < storage_[var].count(); i++) {

                    QString ref = storage_[var][i].notes;
                    QStringList split = ref.split(',');
                    if(split.count() == 1 )
                        continue;
                     if(split.count() == 2){
                         ref.clear();
                         ref.append(split[0]).append(", ").append(split[1]);
                          storage_[var][i].notes.clear();
                          storage_[var][i].notes.append(ref);
                         continue;
                     }
                     QString ref_ = split[0];
                     ref_.remove(QRegExp("[^A-Za-zА-Яа-я]")); // C1 == C
                     //C1 C2 C4 C5 C6 C7 C10 == 1-2,4-5-6-7,10
                    for(int j = 0; j < split.count() - 1; j+=2){
                        int ref1 = (split[j].remove(QRegExp("[A-Za-zА-Яа-я]"))).toInt();
                        int ref2 = (split[j+1].remove(QRegExp("[A-Za-zА-Яа-я]"))).toInt();
                       if(ref2 == ref1 + 1)
                           split.insert(j + 1, "...");
                       else
                           split.insert(j + 1, ", ");

                    }
                    for(int j = 0; j < split.count() - 2; ){

                        if( (split.at(j) == split.at(j + 2)) && ((split.at(j)  == "..." )) ){
                            split.removeAt(j); //удаляю j+1, т.к. функция идет с 1
                            split.removeAt(j);
                            j--;
                            continue;
                        }
                        j++;
                    }
                     // ситуация 1...2,4,6
                    for(int j = 0; j < split.count() - 2; j++ ){

                        int s1 = split.at(j).toInt();
                        int s2 = split.at(j + 2).toInt();
                        if(s1 + 1 == s2){
                            if(split.at(j + 1) == "..."){
                                split[j + 1] = ", ";
                            }
                        }


                    }
                    //Возврат префикса
                    for(int i = 0; i < split.count(); i+=2)
                        split[i].prepend(ref_);
                    ref_.clear();
                    foreach (auto var, split) {
                        ref_.append(var);
                    }
                     storage_[var][i].notes.clear();
                     storage_[var][i].notes.append(ref_);
            }
        }




        return storage_;
    }


};

#endif // DATASTORAGE_H
