#include "MaskedEventParticles.h"


namespace chanser{


  void MaskedEventParticles::AssignVectors(EventParticles* ep){
    //Link to all  EventParticle vectors
    SetMapVector(2212,(&ep->_vecProtons));
    SetMapVector(-2212,(&ep->_vecAntiProtons));
    SetMapVector(2112,(&ep->_vecNeutrons));
    SetMapVector(211,(&ep->_vecPiPs));
    SetMapVector(-211,(&ep->_vecPiMs));
    SetMapVector(111,(&ep->_vecPi0s));
    SetMapVector(321,(&ep->_vecKPs));
    SetMapVector(-321,(&ep->_vecKMs));
    SetMapVector(11,(&ep->_vecEls));
    SetMapVector(-11,(&ep->_vecPos));
    SetMapVector(22,(&ep->_vecGams));
    SetMapVector(PosID(),(&ep->_vecPlus));
    SetMapVector(NegID(),(&ep->_vecMinus));
    SetMapVector(0,(&ep->_vec0));
    SetMapVector(45,(&ep->_vec45));

    //so we don't have to use the map in the event loop
    //Must call this at the end of any derived class AssignVectors
    SetPidVectors();
 
  }
  void MaskedEventParticles::PrintMask() const{
    Info("MaskedEventParticles::PrintMask() ",Form("Masking EventParticles with = %s",Class_Name()),"");
 
  }
  void MaskedEventParticles::SetPidVectors(){
    // std::cout<<"MaskedEventParticles::SetPidVectors() "<<_pids.size()<<" "<<_pidParticles.size()<<std::endl;
    _pidParticles.clear();
    for (auto const& pid: _pids)
      _pidParticles.push_back(GetParticleVector(pid));
  }
  void MaskedEventParticles::PidCounter(){
    //remake vector of pid numbers for TopologyManager
    _pidCounts.clear();
    for(auto i=0;i<_pids.size();++i){
      AddPids(_pids[i],_pidParticles[i]);
    }
    std::sort(_pidCounts.begin(),_pidCounts.end());
  }
  
  void  MaskedEventParticles::AddPids(const Short_t pid,const particles_ptrs* vec){
    auto const addN=vec->size();
    auto const nextIndex=_pids.size();
    _pidCounts.reserve(nextIndex+addN);
    for(auto i=nextIndex;i<nextIndex+addN;++i)
      _pidCounts.emplace_back(pid);
    
  }
  particle_ptr MaskedEventParticles::NextParticle(Short_t pid,UInt_t& entry){
    auto vec= GetParticleVector(pid);
    // std::cout<<"MaskedEventParticles::NextParticle "<<vec->size()<<" "<<entry<<std::endl;
    if(entry>=vec->size())return nullptr;
    // std::cout<<"MaskedEventParticles::NextParticle "<<vec->size()<<" "<<entry<<std::endl;
    
    return  vec->at(entry++);
    
  }
  #include <TDirectory.h>
  void MaskedEventParticles::ReadyFile(TString outDir){
    auto saveDir=gDirectory;
    _outFile.reset(TFile::Open(outDir+Class_Name() +".root","recreate"));
    saveDir->cd();
  }
  
  void  MaskedEventParticles::Write(TObject& obj ){
    if(_outFile.get()==nullptr) return;
    
    auto saveDir=gDirectory;
    _outFile->cd();
    obj.Write();
    saveDir->cd();
  }
  
}
