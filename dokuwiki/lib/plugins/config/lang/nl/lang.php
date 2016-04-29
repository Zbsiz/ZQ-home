<?php

/**
 * @license    GPL 2 (http://www.gnu.org/licenses/gpl.html)
 *
 * @author Pieter van der Meulen <pieter@vdmeulen.net>
 * @author Wouter Schoot <wouter@schoot.org>
 * @author John de Graaff <john@de-graaff.net>
 * @author Niels Schoot <niels.schoot@quintiq.com>
 * @author Dion Nicolaas <dion@nicolaas.net>
 * @author Danny Rotsaert <danny.rotsaert@edpnet.be>
 * @author Marijn Hofstra hofstra.m@gmail.com
 * @author Matthias Carchon webmaster@c-mattic.be
 * @author Marijn Hofstra <hofstra.m@gmail.com>
 * @author Timon Van Overveldt <timonvo@gmail.com>
 * @author Jeroen
 * @author Ricardo Guijt <ricardoguijt@gmail.com>
 * @author Gerrit <klapinklapin@gmail.com>
 * @author Hugo Smet <hugo.smet@scarlet.be>
 * @author hugo smet <hugo.smet@scarlet.be>
 */
$lang['menu']                  = 'Configuratie-instellingen';
$lang['error']                 = 'De instellingen zijn niet gewijzigd wegens een incorrecte waarde, kijk je wijzigingen na en sla dan opnieuw op.<br />Je kunt de incorrecte waarde(s) herkennen aan de rode rand.';
$lang['updated']               = 'Instellingen met succes opgeslagen.';
$lang['nochoice']              = '(geen andere keuzemogelijkheden)';
$lang['locked']                = 'Het bestand met instellingen kan niet worden gewijzigd. Als dit niet de bedoeling <br /> is, controleer dan de naam en de permissies voor het lokale installingenbestand.';
$lang['danger']                = 'Gevaar: Het wijzigen van deze optie kan er voor zorgen dat uw wiki en het configuratiemenu niet langer toegankelijk zijn.';
$lang['warning']               = 'Waarschuwing: Het wijzigen van deze optie kan onverwachte gedragingen veroorzaken.';
$lang['security']              = 'Beveiligingswaarschuwing: Het wijzigen van deze optie kan een beveiligingsrisico inhouden.';
$lang['_configuration_manager'] = 'Configuratiemanager';
$lang['_header_dokuwiki']      = 'DokuWiki-instellingen';
$lang['_header_plugin']        = 'Plugin-instellingen';
$lang['_header_template']      = 'Template-instellingen';
$lang['_header_undefined']     = 'Ongedefinieerde instellingen';
$lang['_basic']                = 'Basisinstellingen';
$lang['_display']              = 'Beeldinstellingen';
$lang['_authentication']       = 'Authenticatie-instellingen';
$lang['_anti_spam']            = 'Anti-spaminstellingen';
$lang['_editing']              = 'Pagina-wijzigingsinstellingen';
$lang['_links']                = 'Link-instellingen';
$lang['_media']                = 'Media-instellingen';
$lang['_notifications']        = 'Meldingsinstellingen';
$lang['_syndication']          = 'Syndication-instellingen';
$lang['_advanced']             = 'Geavanceerde instellingen';
$lang['_network']              = 'Netwerkinstellingen';
$lang['_msg_setting_undefined'] = 'Geen metadata voor deze instelling.';
$lang['_msg_setting_no_class'] = 'Geen class voor deze instelling.';
$lang['_msg_setting_no_default'] = 'Geen standaard waarde.';
$lang['title']                 = 'Titel van de wiki';
$lang['start']                 = 'Naam startpagina';
$lang['lang']                  = 'Taal';
$lang['template']              = 'Template ofwel het design van de wiki.';
$lang['tagline']               = 'Ondertitel (als het template dat ondersteunt)';
$lang['sidebar']               = 'Zijbalk-paginanaam (als het template dat ondersteunt), leeg veld betekent geen zijbalk';
$lang['license']               = 'Onder welke licentie zou je tekst moeten worden gepubliceerd?';
$lang['savedir']               = 'Directory om data op te slaan';
$lang['basedir']               = 'Basisdirectory';
$lang['baseurl']               = 'Basis-URL';
$lang['cookiedir']             = 'Cookie pad. Laat leeg om de basis URL te gebruiken.';
$lang['dmode']                 = 'Directory-aanmaak-modus (directory creation mode)';
$lang['fmode']                 = 'Bestandaanmaak-modus (file creation mode)';
$lang['allowdebug']            = 'Debug toestaan <b>uitzetten indien niet noodzakelijk!</b>';
$lang['recent']                = 'Het aantal regels in Recente wijzigingen';
$lang['recent_days']           = 'Hoeveel recente wijzigingen bewaren (dagen)';
$lang['breadcrumbs']           = 'Aantal broodkruimels. Zet dit op 0 om uit te schakelen.';
$lang['youarehere']            = 'Gebruik hiërarchische broodkruimels (waarschijnlijk wil je dan de optie hierboven uitschakelen)';
$lang['fullpath']              = 'Volledig pad van pagina\'s in de footer weergeven';
$lang['typography']            = 'Breng typografische wijzigingen aan';
$lang['dformat']               = 'Datum formaat (zie de PHP <a href="http://www.php.net/strftime">strftime</a> functie)';
$lang['signature']             = 'Tekst die ingevoegd wordt met de Handtekening-knop in het bewerkvenster.';
$lang['showuseras']            = 'Hoe de gebruiker die de pagina het laatst wijzigde weergeven';
$lang['toptoclevel']           = 'Bovenste niveau voor inhoudsopgave';
$lang['tocminheads']           = 'Minimum aantal koppen dat bepaald of een index gemaakt wordt';
$lang['maxtoclevel']           = 'Laagste niveau voor inhoudsopgave';
$lang['maxseclevel']           = 'Laagste sectiewijzigingsniveau';
$lang['camelcase']             = 'CamelCase gebruiken voor links';
$lang['deaccent']              = 'Paginanamen ontdoen van vreemde tekens';
$lang['useheading']            = 'Eerste kopje voor paginanaam gebruiken';
$lang['sneaky_index']          = 'Met de standaardinstellingen zal DokuWiki alle namespaces laten zien in de index. Het inschakelen van deze optie zorgt ervoor dat de namespaces waar de gebruiker geen leestoegang tot heeft, verborgen worden. Dit kan resulteren in het verbergen van subnamespaces waar de gebruiker wel toegang to heeft. Dit kan de index onbruikbaar maken met bepaalde ACL-instellingen.';
$lang['hidepages']             = 'Verberg deze pagina\'s in zoekresultaten, de index en andere automatische indexen (regular expressions)';
$lang['useacl']                = 'Gebruik access control lists';
$lang['autopasswd']            = 'Zelf wachtwoorden genereren';
$lang['authtype']              = 'Authenticatiemechanisme';
$lang['passcrypt']             = 'Encryptie-methode voor wachtwoord ';
$lang['defaultgroup']          = 'Standaardgroep, alle nieuwe gebruikers worden hierin geplaatst';
$lang['superuser']             = 'Superuser - een groep of gebruiker of kommalijst (gebruiker1,@groep1,gebruiker2) met volledige toegang tot alle pagina\'s en functies, ongeacht de ACL instellingen';
$lang['manager']               = 'Beheerder - een groep of gebruiker of kommalijst (gebruiker1,@groep1,gebruiker2) met toegang tot bepaalde beheersfunctionaliteit';
$lang['profileconfirm']        = 'Bevestig profielwijzigingen met wachtwoord';
$lang['rememberme']            = 'Permanente login cookie toestaan (onthoud mij)';
$lang['disableactions']        = 'Aangevinkte DokuWiki-akties uitschakelen';
$lang['disableactions_check']  = 'Controleer';
$lang['disableactions_subscription'] = 'Inschrijven/opzeggen';
$lang['disableactions_wikicode'] = 'Bron bekijken/exporteer rauw';
$lang['disableactions_profile_delete'] = 'Schrap eigen account';
$lang['disableactions_other']  = 'Andere akties (gescheiden door komma\'s)';
$lang['disableactions_rss']    = 'XML Syndication (RSS)';
$lang['auth_security_timeout'] = 'Authenticatiebeveiligings-timeout (seconden)';
$lang['securecookie']          = 'Moeten cookies die via HTTPS gezet zijn alleen via HTTPS verzonden worden door de browser? Zet deze optie uit als alleen het inloggen op de wiki beveiligd is, maar het gebruik verder niet.';
$lang['remote']                = 'Activeer het remote API-systeem. Hiermee kunnen andere applicaties de wiki benaderen via XML-RPC of andere mechanismen.';
$lang['remoteuser']            = 'Beperk toegang tot de remote API tot deze komma-lijst van groepen of gebruikers. Leeg betekent toegang voor iedereen.';
$lang['usewordblock']          = 'Blokkeer spam op basis van woordenlijst';
$lang['relnofollow']           = 'Gebruik rel="nofollow" voor externe links';
$lang['indexdelay']            = 'Uitstel voor indexeren (sec)';
$lang['mailguard']             = 'E-mailadressen onherkenbaar maken';
$lang['iexssprotect']          = 'Controleer geüploade bestanden op mogelijk schadelijke JavaScript of HTML code';
$lang['usedraft']              = 'Sla automatisch een concept op tijdens het wijzigen';
$lang['htmlok']                = 'Embedded HTML toestaan';
$lang['phpok']                 = 'Embedded PHP toestaan';
$lang['locktime']              = 'Maximum leeftijd voor lockbestanden (sec)';
$lang['cachetime']             = 'Maximum leeftijd voor cache (sec)';
$lang['target____wiki']        = 'Doelvenster voor interne links';
$lang['target____interwiki']   = 'Doelvenster voor interwiki-links';
$lang['target____extern']      = 'Doelvenster voor externe links';
$lang['target____media']       = 'Doelvenster voor medialinks';
$lang['target____windows']     = 'Doelvenster voor windows links';
$lang['mediarevisions']        = 'Mediarevisies activeren?';
$lang['refcheck']              = 'Controleer of er verwijzingen bestaan naar een mediabestand voor het wijderen';
$lang['gdlib']                 = 'Versie GD Lib ';
$lang['im_convert']            = 'Path naar ImageMagick\'s convert tool';
$lang['jpg_quality']           = 'JPG compressiekwaliteit (0-100)';
$lang['fetchsize']             = 'Maximum grootte (bytes) die fetch.php mag downloaden van externe URLs, bijv. voor cachen of herschalen van externe afbeeldingen.';
$lang['subscribers']           = 'Ondersteuning pagina-inschrijving aanzetten';
$lang['subscribe_time']        = 'Inschrijvingsmeldingen en samenvattingen worden na deze tijdsduur (in seconden) verzonden. Deze waarde dient kleiner te zijn dan de tijd ingevuld bij "Hoeveel recente wijzigingen bewaren (dagen)"';
$lang['notify']                = 'Stuur altijd e-mailnotificaties naar dit adres';
$lang['registernotify']        = 'Stuur altijd informatie over nieuw geregistreerde gebruikers naar dit e-mailadres';
$lang['mailfrom']              = 'E-mailadres van afzender voor automatische e-mail';
$lang['mailprefix']            = 'Te gebruiken voorvoegsel voor onderwerp automatische email. Leeglaten gebruik de wikititel.';
$lang['htmlmail']              = 'Zend multipart HTML e-mail. Dit ziet er beter uit, maar is groter. Uitschakelen betekent e-mail in platte tekst.';
$lang['sitemap']               = 'Genereer Google sitemap (dagen). 0 betekent uitschakelen.';
$lang['rss_type']              = 'XML feed type';
$lang['rss_linkto']            = 'XML feed linkt naar';
$lang['rss_content']           = 'Wat moet er in de XML feed items weergegeven worden?';
$lang['rss_update']            = 'XML feed verversingsinterval (sec)';
$lang['rss_show_summary']      = 'XML feed samenvatting in titel weergeven';
$lang['rss_media']             = 'Welk type verandering moet in de XML feed worden weergegeven?';
$lang['updatecheck']           = 'Controleer op nieuwe versies en beveiligingswaarschuwingen? DokuWiki moet hiervoor contact opnemen met update.dokuwiki.org.';
$lang['userewrite']            = 'Gebruik nette URL\'s';
$lang['useslash']              = 'Gebruik slash (/) als scheiding tussen namepaces in URL\'s';
$lang['sepchar']               = 'Woordscheider in paginanamen';
$lang['canonical']             = 'Herleid URL\'s tot hun basisvorm';
$lang['fnencode']              = 'Methode om niet-ASCII bestandsnamen te coderen.';
$lang['autoplural']            = 'Controleer op meervoudsvormen in links';
$lang['compression']           = 'Compressiemethode voor attic-bestanden';
$lang['gzip_output']           = 'Gebruik gzip Content-Encoding voor xhtml';
$lang['compress']              = 'Compacte CSS en javascript output';
$lang['cssdatauri']            = 'Maximale omvang in bytes van in CSS gelinkte afbeeldingen die bij de stylesheet moeten worden ingesloten ter reductie van de HTTP request header overhead. <code>400</code> tot <code>600</code> is een geschikte omvang. Stel de omvang in op <code>0</code> om deze functionaliteit uit te schakelen.';
$lang['send404']               = 'Stuur "HTTP 404/Page Not Found" voor niet-bestaande pagina\'s';
$lang['broken_iua']            = 'Is de ignore_user_abort functie onbruikbaar op uw systeem? Dit kan een onbruikbare zoekindex tot gevolg hebben. IIS+PHP/CGI staat hier bekend om. Zie <a href="http://bugs.dokuwiki.org/?do=details&amp;task_id=852">Bug 852</a> voor meer informatie.';
$lang['xsendfile']             = 'Gebruik de X-Sendfile header om de webserver statische content te laten versturen? De webserver moet dit wel ondersteunen.';
$lang['renderer_xhtml']        = 'Weergavesysteem voor de standaard (xhtml) wiki-uitvoer';
$lang['renderer__core']        = '%s (dokuwiki core)';
$lang['renderer__plugin']      = '%s (plugin)';
$lang['dnslookups']            = 'DokuWiki zoekt de hostnamen van IP-adressen van gebruikers die pagina wijzigen op. Schakel deze optie uit als je geen of een langzame DNS server hebt.';
$lang['proxy____host']         = 'Proxy server';
$lang['proxy____port']         = 'Proxy port';
$lang['proxy____user']         = 'Proxy gebruikersnaam';
$lang['proxy____pass']         = 'Proxy wachtwoord';
$lang['proxy____ssl']          = 'Gebruik SSL om een verbinding te maken met de proxy';
$lang['proxy____except']       = 'Reguliere expressie om URL\'s te bepalen waarvoor de proxy overgeslagen moet worden.';
$lang['safemodehack']          = 'Safemode hack aanzetten';
$lang['ftp____host']           = 'FTP server voor safemode hack';
$lang['ftp____port']           = 'FTP port voor safemode hack';
$lang['ftp____user']           = 'FTP gebruikersnaam voor safemode hack';
$lang['ftp____pass']           = 'FTP wachtwoord voor safemode hack';
$lang['ftp____root']           = 'FTP root directory voor safemode hack';
$lang['license_o_']            = 'Geen gekozen';
$lang['typography_o_0']        = 'geen';
$lang['typography_o_1']        = 'Alleen dubbele aanhalingstekens';
$lang['typography_o_2']        = 'Alle aanhalingstekens (functioneert mogelijk niet altijd)';
$lang['userewrite_o_0']        = 'geen';
$lang['userewrite_o_1']        = '.htaccess';
$lang['userewrite_o_2']        = 'DokuWiki intern';
$lang['deaccent_o_0']          = 'uit';
$lang['deaccent_o_1']          = 'accenten verwijderen';
$lang['deaccent_o_2']          = 'romaniseer';
$lang['gdlib_o_0']             = 'GD Lib niet beschikbaar';
$lang['gdlib_o_1']             = 'Version 1.x';
$lang['gdlib_o_2']             = 'Autodetectie';
$lang['rss_type_o_rss']        = 'RSS 0.91';
$lang['rss_type_o_rss1']       = 'RSS 1.0';
$lang['rss_type_o_rss2']       = 'RSS 2.0';
$lang['rss_type_o_atom']       = 'Atom 0.3';
$lang['rss_type_o_atom1']      = 'Atom 1.0';
$lang['rss_content_o_abstract'] = 'Abstract';
$lang['rss_content_o_diff']    = 'Unified Diff';
$lang['rss_content_o_htmldiff'] = 'Diff-tabel in HTML';
$lang['rss_content_o_html']    = 'Volledige pagina-inhoud in HTML';
$lang['rss_linkto_o_diff']     = 'verschillen';
$lang['rss_linkto_o_page']     = 'de gewijzigde pagina';
$lang['rss_linkto_o_rev']      = 'lijst van revisies';
$lang['rss_linkto_o_current']  = 'de huidige pagina';
$lang['compression_o_0']       = 'geen';
$lang['compression_o_gz']      = 'gzip';
$lang['compression_o_bz2']     = 'bz2';
$lang['xsendfile_o_0']         = 'niet gebruiken';
$lang['xsendfile_o_1']         = 'Merkgebonden lighttpd header (voor release 1.5)';
$lang['xsendfile_o_2']         = 'Standaard X-Sendfile header';
$lang['xsendfile_o_3']         = 'Merkgebonden Nginx X-Accel-Redirect header';
$lang['showuseras_o_loginname'] = 'Loginnaam';
$lang['showuseras_o_username'] = 'Volledige naam';
$lang['showuseras_o_username_link'] = 'Gebruikers volledige naam als interwiki gebruikers link';
$lang['showuseras_o_email']    = 'E-mailadres (onherkenbaar gemaakt volgens mailguard-instelling)';
$lang['showuseras_o_email_link'] = 'E-mailadres als mailto: link';
$lang['useheading_o_0']        = 'Nooit';
$lang['useheading_o_navigation'] = 'Alleen navigatie';
$lang['useheading_o_content']  = 'Alleen wiki inhoud';
$lang['useheading_o_1']        = 'Altijd';
$lang['readdircache']          = 'Maximale leeftijd voor readdir cache (in seconden)';
