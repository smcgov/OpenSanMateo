<?php $size = explode('x', $settings['size']); ?>

<?php if (isset($settings['text_address'])): ?>
  <div><?php print $settings['text_address']; ?></div>
<?php endif; ?>

<div id="map_canvas" style="width: <?php print $size[0]; ?>px; height: <?php print $size[1]; ?>px;">
  <noscript><?php print $image; ?></noscript>
</div>

<script type="text/javascript">
  var address = '<?php print $address; ?>';

  var myOptions = {
    zoom: <?php print $settings['zoom']; ?>,
    mapTypeId: google.maps.MapTypeId.<?php print strtoupper($settings['maptype']); ?>
    //disableDefaultUI: true,
    //scrollwheel: false,
    //draggable: false,
    //disableDoubleClickZoom: true
  }
  var map = new google.maps.Map(document.getElementById('map_canvas'), myOptions);
  
  <?php if (isset($settings['info_window'])): ?>
    // info window
    var content = document.createElement('div');
    content.className = 'info-window';
    content.innerHTML = '<?php print $settings['text_address']; ?>';
    
    var infowindow = new google.maps.InfoWindow({
      content: content
    });
  <?php endif; ?>
  
  <?php foreach ($kml_paths as $kml_path): ?>
    var ctaLayer = new google.maps.KmlLayer('<?php print $kml_path; ?>');
    ctaLayer.setMap(map);
  <?php endforeach; ?>

  var geocoder = new google.maps.Geocoder();

  geocoder.geocode({'address': address}, function(results, status) {
    if (status == google.maps.GeocoderStatus.OK) {
      map.setCenter(results[0].geometry.location);
      var marker = new google.maps.Marker({
        map: map,
        position: results[0].geometry.location
      });
      <?php if (isset($settings['info_window'])): ?>
        // info window
        google.maps.event.addListener(marker, 'click', function() {
          infowindow.open(map,marker);
        });
      <?php endif; ?>
    }
 });
</script>