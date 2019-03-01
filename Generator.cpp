#include "Generator.hpp"

Generator::Generator() : m_thr_generate(){ 

        m_control_mutex = true;   

        m_token = -999999;

}

int  Generator::createRandomNumber(int from, int to ){

        std::mt19937 mt(rd());

        std::uniform_int_distribution<int> dist(from,to); 

        return dist(mt);
}

void Generator::Generate(){
        
        m_mutex.lock();

        m_control_mutex = false;     
      
        int val = createRandomNumber(-10,10);

        m_queue.push(val);      

        m_mutex.unlock();  

        m_control_mutex = true;

}

int Generator::takeNewInt(){
        
        int val;

        if (!m_queue.empty()) {
                
                val = m_queue.front();

                m_queue.pop();

        }

        return val;

}

void Generator::freeMutex(int token) {
        
        if (token == m_token){

                m_mutex.unlock();   

                m_control_mutex = true;

        }

}

bool Generator::takeMutex(int token){

         if ( m_control_mutex ){

                 m_mutex.lock();

                 m_control_mutex = false;

                 m_token = token;

                 return true;

         }

       return false;  

}

void Generator::Run(){

        m_thr_generate = std::thread(&Generator::Generate,this);

        if (m_thr_generate.joinable()) m_thr_generate.join();
        
        //std::this_thread::sleep_for(std::chrono::seconds(1));
}

Generator::~Generator(){

}