# CXML Reader

## SImplementation Structure

### StartElementHandler

void StartElementHandler(const std::string &name, const std::vector<std::string> &attrs);

This handles the start element event while undergoing XML parsing. It takes two parameters: name and attrs, which refer to the ame of the elemnt and a vector of value pairs associate with the element, respectively. 

This set's the entity's name and type and populates the entity's attributes from the vector. It also pushes the entity onto the queue.

### EndElementHandler

void EndElementHandler(const std::string &name);

This handles the end element event while undergoing XML parsing. It takes on parameter which is the name of the element and creates an entity to represent it, setting the entity's name and type then pushing it onty the queue.

### CharacterDataHandler

void CharacterDataHandler(const std::string &data);

This handles the character data while undergoing parsing.

It takes one parameter 'data' which is just the character data that is identified. It then creates an entity representing the character data and sets the entity's data and type, then pushes it onto the queue.

### End

bool End() const;

This simply checks if the queue is empty or not, and returns True if it is.

### ReadEntity

bool ReadEntity(SXMLEntity &entity, bool skipcdata);

This reads the next entity in the order from the data source. It takes two parameters: entity and skipcdata, which are references to store the read entity and a flag indicating whether or not we need to skip the character data, respectively. 

This reads from the data source and uses Expat to parse the data. Then, it populates the provided entity with the NEXT entity fromt he queue, and returns True if it was successful.
