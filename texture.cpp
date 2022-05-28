#include <iostream>
#include "texture.h"

Texture::Texture(GLenum TextureTarget, const std::string& FileName)
{
    m_textureTarget = TextureTarget;
    m_fileName = FileName;
    m_pImage = NULL;
}

bool Texture::Load()
{
    try {
        m_pImage = new Magick::Image(m_fileName);//загрузка текстуры в памаять 
        m_pImage->write(&m_blob, "RGBA"); 
    }
    catch (Magick::Error& Error) { //записываем изображение
        std::cout << "Error loading texture '" << m_fileName << "': " << Error.what() << std::endl;
        return false;
    }

    glGenTextures(1, &m_textureObj); //генерирует указанное число объектов текстур и помещает их в указатель на массив 
    glBindTexture(m_textureTarget, m_textureObj); //указываем, с каким объектом текстуры работаем
    glTexImage2D(m_textureTarget, 0, GL_RGB, m_pImage->columns(), m_pImage->rows(), -0.5, GL_RGBA, GL_UNSIGNED_BYTE, m_blob.data()); //загрузка текстуры
    glTexParameterf(m_textureTarget, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //увеличение/уменьшение текстуры
    glTexParameterf(m_textureTarget, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return true;
}

void Texture::Bind(GLenum TextureUnit) //принимает модуль текстуры
{
    glActiveTexture(TextureUnit);
    glBindTexture(m_textureTarget, m_textureObj);
}