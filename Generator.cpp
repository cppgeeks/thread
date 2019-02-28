#include "Generator.hpp"

Generator::Generator() : m_thr_generate(){  
           
}

void Generator::Generate(){
        
        m_mutex.lock();

        std::mt19937 mt(rd());

        std::uniform_int_distribution<int> dist(-10,10); 

        auto val = dist(mt);

        m_queue.push(val);      

        m_mutex.unlock();  

}

int Generator::takeNewInt(){
        
        int val;

        if (!m_queue.empty()) {
                
                val = m_queue.front();

                m_queue.pop();

        }

        return val;

}

void Generator::setMutex(){
        
        m_mutex.unlock();

}

void Generator::takeMutex(){

        m_mutex.lock();

}
void Generator::Run(){

        m_thr_generate = std::thread(&Generator::Generate,this);
          
        // m_thr_generate.detach();
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
}

Generator::~Generator(){

        if (m_thr_generate.joinable()) m_thr_generate.join();

}