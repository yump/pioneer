#ifndef _TEXTUREFONT_H
#define _TEXTUREFONT_H

#include "Font.h"
#include "FontConfig.h"

class TextureFont : public Font
{
public:
	TextureFont(FontManager &fm, const std::string &config_filename);

	void RenderString(const char *str, float x, float y);
	void RenderMarkup(const char *str, float x, float y);
	void MeasureString(const char *str, float &w, float &h);
	// of Ms
	float GetHeight() const { return m_height; }
	float GetWidth() const { return m_width; }
	float GetDescender() const { return m_descender; }
	struct glfglyph_t {
		unsigned int tex;
		float advx, advy;
		float width, height;
		int offx, offy;
	};
	const glfglyph_t &GetGlyph(Uint32 ch) { return m_glyphs[ch]; }

private:
	void RenderGlyph(Uint32 chr, float x, float y);
	float m_height;
	float m_width;
	float m_descender;
	int m_texSize, m_pixSize;
	std::map<Uint32,glfglyph_t> m_glyphs;
};

#endif
