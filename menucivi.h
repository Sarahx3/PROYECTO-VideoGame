#include "civilizacion.h"

void menu(Civilizacion*ptr){
                string opc;
                while(true){
                    cout<< endl;
                    cout<< "1) Agregar aldeano" << endl;//
                    cout<< "2) Eliminar aldeano" << endl;//
                    cout<< "3) Clasificar aldeanos" << endl;//
                    cout<< "4) Buscar aldeano" << endl;//
                    cout<< "5) Modificar aldeano" << endl;
                    cout<< "6) Mostrar aldeanos" << endl;//
                    cout<< "0) Atras" << endl;//
                    cout << "Opcion:  ";
                    getline(cin, opc);
                    if(opc == "1"){ //agregar
                        Aldeano aux;
                        cin >> aux;
                        string opc1;

                        cout<< "1) Inicio" << endl;
                        cout<< "2) Final" << endl;
                        cout<< "Agregar: ";
                        getline(cin,opc1);
                        if(opc1 == "1"){
                            ptr->agregarInicio(aux);
                        }
                        if(opc1 == "2"){
                            ptr->agregarFinal(aux);
                        }
                    }

                    if(opc == "2"){//eliminar
                        string str;
                        string opc1;
                        cout<< endl;
                        cout<< "1) Nombre" << endl;
                        cout<< "2) Salud < a X" << endl;
                        cout<< "3) Edad >= 60" << endl;
                        cout<< "Eliminar por: ";
                        getline(cin,opc1);
                        if(opc1 == "1"){
                            cout << "Aldeano a eliminar: ";
                            getline(cin,str);
                            ptr->eliminarNombre(str);
                        }
                        if(opc1 == "2"){
                            size_t x;
                            cout<<"Salud menor a: ";
                            cin >> x; cin.ignore();
                            ptr->eliminarSalud(x);
                        }
                        if(opc1 == "3"){
                            ptr->eliminarEdad();
                        }

                    }

                    if(opc == "3"){//clasificar
                        string opc1;
                        cout<<endl;
                        cout<< "1) Nombre" << endl;
                        cout<< "2) Edad" << endl;
                        cout<< "3) Salud" << endl;
                        cout<< "Clasificar por: ";
                        getline(cin,opc1);
                        if(opc1 == "1"){
                            ptr->ordenarNombre();
                        }
                        if(opc1 == "2"){
                            ptr->ordenarEdad();
                        }
                        if(opc1 == "3"){
                            ptr->ordenarSalud();
                        }

                    }

                    if(opc == "4"){//buscar
                        string str2;
                        Aldeano aux;

                        cout<< "Aldeano a buscar: ";
                        getline(cin,str2);
                        aux.setNombre(str2);

                        Aldeano *ptr1 = ptr->buscar(aux);
                        if(ptr1 ==nullptr){
                            cout << "no se encontro el Aldeano" << endl;
                        }
                        else{
                            cout << endl;
                            cout<<"Aldeano encontrado: " << endl;
                            cout<< *ptr1<< endl;
                            
                        }
                    }

                    if(opc == "5"){//modificar
                        string str2;
                        Aldeano aux;

                        cout<< "Aldeano a modificar: ";
                        getline(cin,str2);
                        aux.setNombre(str2);

                        Aldeano *ptr1 = ptr->buscar(aux);
                        if(ptr1 ==nullptr){
                            cout << "no se encontro el Aldeano" << endl;
                        }
                        else{
                            cout << endl;
                            cout<<"Aldeano encontrado: " << endl;
                            cout<< *ptr1<< endl;
                            cout<<endl;
                            string opc1,mystr;
                            size_t edad; float salud;
                            cout<< "1) Nombre" << endl;
                            cout<< "2) Edad" << endl;
                            cout<< "3) Genero" << endl;
                            cout<< "4) Salud" << endl;
                            cout << "Modificar:  ";
                            getline(cin, opc1);
                            if (opc1 == "1"){
                                cout <<"Nombre nuevo: ";
                                getline(cin,mystr);
                                ptr1->setNombre(mystr);
                            }
                            else if(opc1 == "2"){
                                cout <<"Edad nueva: ";
                                cin >> edad; cin.ignore();
                                ptr1->setEdad(edad);
                            }
                            else if(opc1 == "3"){
                                cout <<"Genero nuevo: ";
                                getline(cin,mystr);
                                ptr1->setGenero(mystr);
                            }
                            else if(opc1 == "4"){
                                cout <<"Salud nueva: ";
                                cin >> salud; cin.ignore();
                                ptr1->setEdad(salud);
                            }
                        }

                    }

                    if(opc == "6"){//mostrar
                        
                        ptr->mostrarAldeanos();
                    }
                    if(opc == "0"){//atras
                        break;
                    }
                }
}