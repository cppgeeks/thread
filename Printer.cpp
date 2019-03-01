#include "Printer.hpp"
#include <iostream>
Printer::Printer() : m_thr_printer_out(){       
}

void Printer::Print(Generator* m_gen){

       int token = m_gen->createRandomNumber(1,99);

       if (m_gen->takeMutex(token)){

            m_mutex.lock();

            std::cout << m_gen->takeNewInt() << std::endl;

            m_mutex.unlock();    

            m_gen->freeMutex(token);    

       }            
       
}


void Printer::Run( Generator* m_gen){       

        m_thr_printer_out = std::thread(&Printer::Print,this,m_gen);

        if ( m_thr_printer_out.joinable() ) m_thr_printer_out.join();
                          
}

Printer::~Printer(){
       
}