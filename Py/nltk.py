import nltk
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize, sent_tokenize
from collections import Counter
from nltk.tag import pos_tag

# Downloading necessary NLTK data
nltk.download('punkt')
nltk.download('averaged_perceptron_tagger')
nltk.download('stopwords')

def count_words(text):
    stop_words = set(stopwords.words('english'))

    # Tokenize the text
    tokenized = sent_tokenize(text)
    for i in tokenized:
      
        # Word tokenizers is used to find the words and punctuation in a string
        wordsList = nltk.word_tokenize(i)

        # Removing stop words from wordList
        wordsList = [w for w in wordsList if not w in stop_words] 

        # Using a Tagger
        tagged = nltk.pos_tag(wordsList)

        # Only include some parts of speech
        includes = ['NN', 'NNS', 'NNP', 'NNPS', 'VB', 'VBD', 'VBG', 'VBN', 'VBP', 'VBZ', 'JJ', 'JJR', 'JJS']
        words = [word for word,pos in tagged if pos in includes]

        # Count the occurrences of each word
        counts = Counter(words)
        print(counts)

# Test with a simple sentence
count_words("The quick brown fox jumps over the lazy dog.")
