#pragma once

#include <map>
#include <SFML/Graphics.hpp>

/**
 * Class to keep track of assets
 */
class AssetManager
{
public:

    /**
     * AssetManagers constructor
     */
    AssetManager() { }

    /**
     * AssetManagers destructor
     */
    ~AssetManager() = default;

    /**
     * Loads different objects texture
     *
     * @param name of the item
     * @param fileName of the item
     */
    void LoadTexture(std::string name, std::string fileName);

    /**
     * Get Objects texture
     *
     * @param name of the texture
     * @return SFML texture of the object
     */
    sf::Texture &GetTexture(std::string name);

    /**
     * Loads different objects texture
     *
     * @param name of the font
     * @param fileName of the font
     */
    void LoadFont(std::string name, std::string fileName);

    
    //sf::Font &GetFont(std::string name);

private:
    std::map<std::string, sf::Texture> _textures; /*!< Map to store textures */
    std::map<std::string, sf::Font> _fonts; /*!< Map to store fonts */
};

