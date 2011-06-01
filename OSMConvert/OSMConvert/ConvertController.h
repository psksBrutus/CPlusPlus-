//
//  ConvertController.h
//  OSM_Konverter
//
//  Created by Marcel Radischat on 01.06.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

//TODO rename 
#ifndef osmController_h
#define osmController_h

//NYI, TODO: Implement!
//#include "osmAnwendung.h"

#include "OSMObject.h"
#include "Plugin.h"
#include "boost/function.hpp"
#include "boost/utility.hpp"

typedef  boost::function< OSMObject*() >  osm_factory;

// Jedes PLugin muss eine Funktion dieses Typs bereitstellen
typedef Plugin* (*GetPluginInterface_t)();

namespace po = boost::program_options;

class ConvertController : boost::noncopyable{
    
private:
	// Optionpanel mit den Programm und Plugin Optionen
	po::options_description desc;
	// Zum erzeugen von callbacks aus den Plugins
	std::map<std::string,osm_factory> osmFactory;
    
	static  ConvertController*	theController;
    
public:
	ConvertController();
    
	~ConvertController();
    
	void RegisterClassFactory( const std::string& name, osm_factory factory );
    
	void registerOptions(boost::program_options::options_description& op);
    
	po::options_description& getOptions();
    
	// Erstellt ein OsmOject. Name ist das verwendete Plugin
	OSMObject* createOsmObject(const std::string& name);
    
	void start(boost::program_options::variables_map& vm);
    
	static ConvertController* GetInstance();
    
};

class ConvertException :public std::exception{
    
public:
	ConvertException() : exception(){}
    
    friend std::ostream& operator<<( std::ostream& os, const ConvertException& e){
		return os << e.what();	
	}
    
    
};
#endif

