import os
import PyPDF2
import pytesseract
from collections import Counter

def ocr_pdfs(directory):
    total_files = 0
    total_dirs = 0
    word_counts = Counter()

    for root, dirs, files in os.walk(directory):
        total_dirs += len(dirs)

        for file in files:
            if file.endswith('.pdf'):
                total_files += 1
                pdf_path = os.path.join(root, file)
                with open(pdf_path, 'rb') as pdf_file:
                    pdf_reader = PyPDF2.PdfReader(pdf_file)
                    num_pages = len(pdf_reader.pages)

                    for page_num in range(num_pages):
                        page = pdf_reader.pages[page_num]
                        text = page.extract_text()
                        words = text.split()
                        word_counts.update(words)

    word_list = sorted(word_counts.items(), key=lambda x: (x[0].islower(), x[0].lower(), x[1]))

    print(f"Total files: {total_files}")
    print(f"Total directories: {total_dirs}")
    print("List of words:")
    print("Word Count Number_Files")
    for word, count in word_list:
        num_files = sum(1 for _, c in word_counts.items() if c >= count)
        print(f"{word} {count} {num_files}")

    return word_list

directory_path = 'pdfs'
ocr_pdfs(directory_path)