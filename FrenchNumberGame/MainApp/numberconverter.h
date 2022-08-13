#ifndef NUMBERCONVERTER_H
#define NUMBERCONVERTER_H

#include <QObject>

class NumberConverter : public QObject
{
    Q_OBJECT
public:
    explicit NumberConverter(QObject *parent = nullptr);
    QString NumberToEnglish(uint number);
    QString NumberToFrench(uint number);
    ~NumberConverter();

private:
    QVector<QString> FrenchNumbersInput;
    void LoadFrenchNumbers();
};

#endif // NUMBERCONVERTER_H
