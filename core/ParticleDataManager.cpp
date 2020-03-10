#include "ParticleDataManager.h"
#include "FinalState.h"

namespace chanser{
    
  void ParticleDataManager::PrintAction(){
    std::cout<<" ParticleDataManager::Print() "<<_particleData.size()<<std::endl;
    	
  }

  ///////////////////////////////////////////////////////////////
  void ParticleDataManager::Configure( FinalState* fs){
 
    auto topos=fs->TopoManager().ObserveTopos(); //const, can't change them
      
         
    MakeOutDir();//directory for saving files
      
    for(auto const& topo : topos){
      auto topo_parts=topo.GetParticles();
   
      auto outfile=_outDir+Form("/ParticleVariables_%d.root%s",topo.ID(),fs->WorkerName().Data());
      auto pdata=ParticleData{GetName(),outfile,topo_parts.size()};
	
      //Loop over all particles in this topology and assign output data
      std::cout<<" ParticleDataManager::Configure particles "<<topo_parts.size()<<std::endl;
	
      UInt_t ip=0;
      for(auto const& particle : topo_parts){
	//Add particle to output data
	pdata.AddParticle(*_outData,particle,topo.GetPartName(ip++));
	  
      }
      //add branches from final state tree
      if(_addFinal)fs->ConfigureOutTree(pdata.GetTree());

      _particleData.push_back(std::move(pdata));

    }
  
  }
  void ParticleDataManager::End(){
      
    for( auto& out : _particleData )
      out.Save();
  }
    
}
